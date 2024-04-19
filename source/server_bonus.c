/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:51:51 by palu              #+#    #+#             */
/*   Updated: 2024/04/19 16:02:24 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int sig, siginfo_t *info, void *ptr)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)ptr;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;	
		kill(info->si_pid, SIGUSR2);
	}
}

int		main(int argc, char **argv)
{
	int					pid;
	struct sigaction	signal;

	if (argc != 1)
	{
		ft_printf("Error launching server try with './server'\n");
		return (1);
	}
	pid = getpid();
	ft_printf("server PID : %d\n", pid);
	ft_printf("Waiting for message...\n");
	signal.sa_sigaction = sighandler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = 0;
	while (argv[1] == NULL)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
	return (0);
}
