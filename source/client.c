/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:10 by palu              #+#    #+#             */
/*   Updated: 2024/04/29 18:06:19 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strchr( const char *s, int c)
{
	char	*dup;
	size_t	i;

	dup = (char *)s;
	i = 0;
	while (i < ft_strlen(dup) + 1)
	{
		if (*(dup + i) == (char)c)
			return (dup + i);
		i++;
	}
	return (NULL);
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

void	ft_send_bits(int pid, char i)
{
	int		bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		ft_printf("Error, wrong amount of argument\n");
		ft_printf("Try like this : ./client [PID] [\"Your message\"]\n");
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	while (argv[2][i] != '\0')
	{
		ft_send_bits(pid, argv[2][i]);
		i++;
	}
	ft_send_bits(pid, '\n');
	return (0);
}
