/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:00 by palu              #+#    #+#             */
/*   Updated: 2024/06/04 16:50:39 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sighandler(int sig)
{
	static char	c;
	static int	i;

	i++;
	if (sig == SIGUSR1)
		c = c | 1;
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	c = c << 1;
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("server PID : %d\n", pid);
	ft_printf("Waiting for message...\n");
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause ();
	return (0);
}
