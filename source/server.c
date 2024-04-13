/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:00 by palu              #+#    #+#             */
/*   Updated: 2024/04/13 19:22:59 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;	
	}
}

int		main(int argc, char **argv)
{
	int		pid;

	if (argc != 1)
	{
		ft_printf("Error launching server try with './server'\n");
		return (1);
	}
	pid = getpid();
	ft_printf("server PID : %d\n", pid);
	ft_printf("Waiting for message...\n");
	while (argv[1] == NULL)
	{
		signal(SIGUSR1, sighandler);
		signal(SIGUSR2, sighandler);
		pause ();
	}
	return (0);
}
