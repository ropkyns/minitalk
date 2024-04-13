/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:11:45 by ropkyns           #+#    #+#             */
/*   Updated: 2024/01/09 16:19:34 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{	
	int	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
