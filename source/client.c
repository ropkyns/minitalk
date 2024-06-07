/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:10 by palu              #+#    #+#             */
/*   Updated: 2024/06/07 17:20:43 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_check(char *s, char *c)
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

static void	ft_send_strlen(int pid, int len)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(100);
	}
}

static void	ft_send_bits(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		len;
	char	*str;

	if (argc != 3 || ft_check(argv[1], "0123456789"))
	{
		ft_printf("Error, try like this : ./client [PID] [\"message\"]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	ft_send_strlen(pid, len);
	i = -1;
	while (str[++i])
		ft_send_bits(pid, str[i]);
	ft_send_bits(pid, str[i]);
	return (0);
}
