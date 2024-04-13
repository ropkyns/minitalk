/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:13:10 by palu              #+#    #+#             */
/*   Updated: 2024/04/13 19:26:32 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main (int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		ft_printf("Error, wrong amount of argument\n");
		ft_printf("Try like this : ./client [PID] [\"message you want to send to the server\"]\n");
		return (1);
	}
	
}
