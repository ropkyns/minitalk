/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:51:47 by palu              #+#    #+#             */
/*   Updated: 2024/05/14 16:35:25 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	errorh(void)
{
	ft_printf("An error has occurred. You may check the server PID");
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * signe);
}

void	ft_send_bits(int pid, char c)
{
	int		bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			if (kill(pid, SIGUSR1) == -1)
				errorh();
		else
			if (kill(pid, SIGUSR2) == -1)
				errorh();
		usleep(500);
		bit++;
	}
}

static void	message_reception(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("message received\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		ft_printf("Error, try like this : ./client [PID] [\"message\"]\n");
		return (1);
	}
	signal(SIGUSR1, &message_reception);
	signal(SIGUSR2, &message_reception);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_send_bits(pid, argv[2][i]);
		i++;
	}
	ft_send_bits(pid, '\n');
	return (0);
}
