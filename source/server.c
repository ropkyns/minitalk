/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:00 by palu              #+#    #+#             */
/*   Updated: 2024/06/06 19:02:06 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int sig, siginfo_t *siginfo, void *vd)
{
	static int	bit = 0;
	static int	i = 0;

	(void)siginfo;
	(void)vd;
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

int	main(void)
{
	int		pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("server PID : %d\n", pid);
	ft_printf("Waiting for message...\n");
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sighandler;
	sigemptyset(&sig.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause ();
	}
	return (0);
}
