/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:04:28 by ropkyns           #+#    #+#             */
/*   Updated: 2024/06/07 17:46:48 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>

# include <stdarg.h>

# include <unistd.h>

int		ft_printf(const char *string, ...);
int		ft_format(char c, va_list args);
int		ft_strlen(char *s);
void	ft_putchar(char c);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long ptr);
void	ft_putptr(unsigned long ptr);
int		ft_len_ptr(unsigned long ptr);
int		len_int(int n);
int		ft_print_int(int n);
void	ft_putnbr(int n);
int		ft_print_unsigned_int(unsigned int n);
void	ft_put_unsigned_nbr(unsigned int nb);
int		ft_print_hexa(unsigned int hex);
int		ft_print_hexa_caps(unsigned int hex);
int		ft_len_hexa(unsigned int hex);
int		ft_atoi(const char *str);

#endif