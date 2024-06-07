/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:00 by palu              #+#    #+#             */
/*   Updated: 2024/06/07 17:58:25 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * recursive_power(nb, power - 1));
}

static void	reset_var(int *len, char **str, int *i)
{
	*len = 0;
	if (str)
	{
		ft_printf("%s\n", str);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	len_str(int *bit, char **str, int *len, int signal)
{
	static int	lvalue = 0;

	if (signal == SIGUSR1)
		lvalue += recursive_power(2, *bit);
	if (*bit == 31)
	{
		*str = malloc((lvalue + 1) * sizeof(char));
		*bit = 0;
		lvalue = 0;
		*len = 1;
		return ;
	}
	(*bit)++;
}

static void	sighandler(int signal)
{
	static int	bit = 0;
	static int	i = 0;
	static int	char_int = 0;
	static int	len = 0;
	static char	*str = 0;

	if (!len)
		len_str(&bit, &str, &len, signal);
	else
	{
		if (signal == SIGUSR1)
			char_int += recursive_power(2, bit);
		if (bit == 7)
		{
			str[i++] = char_int;
			bit = 0;
			if (char_int == 0)
				return (reset_var(&len, &str, &i));
			char_int = 0;
			return ;
		}
		bit++;
	}
}

int	main(void)
{
	int		pid;

	pid = (int)(getpid());
	ft_printf("server PID : %d\n", pid);
	ft_printf("Waiting for message...\n");
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause ();
	return (0);
}
/* https://github.com/Ysoroko/minitalk/tree/master */