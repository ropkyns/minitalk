/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:28:54 by paulmart          #+#    #+#             */
/*   Updated: 2024/06/09 16:20:09 by paulmart         ###   ########.fr       */
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

static void	ft_send_next_char_bit_by_bit(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(100);
	}
}

static void	send_strlen(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_to_send;
	int		len;
	int		i;

	if (argc != 3 || ft_check(argv[1], "0123456789"))
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	str_to_send = argv[2];
	len = ft_strlen(str_to_send);
	i = -1;
	send_strlen(len, pid);
	while (str_to_send[++i])
		ft_send_next_char_bit_by_bit(str_to_send[i], pid);
	ft_send_next_char_bit_by_bit(str_to_send[i], pid);
}