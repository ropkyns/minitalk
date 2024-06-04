/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:10 by palu              #+#    #+#             */
/*   Updated: 2024/06/04 17:05:25 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check(char *s, char *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] != c[i] && c[i])
			i++;
		if (s[j] != c[i])
			return (1);
		i = 0;
		j++;
	}
	if (ft_strlen(s) <= 0)
		return (1);
	return (0);
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

void	ft_send_bits(int pid, char *str)
{
	int		i;
	int		bit;
	char	message;

	i = -1;
	while (str[++i] != '\0')
	{
		bit = 8;
		while (--bit >= 0)
		{
			message = (str[i] >> bit) & 1;
			if (message == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3 || ft_check(argv[1], "0123456789"))
	{
		ft_printf("Error, try like this : ./client [PID] [\"message\"]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_send_bits(pid, argv[2]);
	ft_send_bits(pid, "\n");
	return (0);
}
