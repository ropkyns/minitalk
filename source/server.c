/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:19:26 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/09 16:34:37 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	reset_var(int *len, char **str, int *i)
{
	*len = 0;
	if (str)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static void	get_strlen(int *curr_bit, char **str, int *received, int s)
{
	static int	lvalue = 0;

	if (s == SIGUSR1)
		lvalue += ft_recursive_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*received = 1;
		*str = ft_calloc_exit(lvalue + 1, sizeof(char));
		*curr_bit = 0;
		lvalue = 0;
		return ;
	}
	(*curr_bit)++;
}

static void	ft_sighangdler(int signal)
{
	static int	int_char = 0;
	static int	bit = 0;
	static int	len = 0;
	static int	i = 0;
	static char	*str = 0;

	if (!len)
		get_strlen(&bit, &str, &len, signal);
	else
	{
		if (signal == SIGUSR1)
			int_char += ft_recursive_power(2, bit);
		if (bit == 7)
		{
			str[i++] = int_char;
			bit = 0;
			if (int_char == 0)
				return (reset_var(&len, &str, &i));
			int_char = 0;
			return ;
		}
		bit++;
	}
}

int	main(void)
{
	int	pid;

	pid = (int)(getpid());
	ft_printf("server PID : %d\n", pid);
	ft_printf("Waiting for message...\n");
	signal(SIGUSR1, ft_sighangdler);
	signal(SIGUSR2, ft_sighangdler);
	while (1)
		usleep(100);
}