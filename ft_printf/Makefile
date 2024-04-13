# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 16:36:40 by ropkyns           #+#    #+#              #
#    Updated: 2024/01/09 17:19:05 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= ft_printf.c ft_utils.c ft_printf_alpha.c ft_printf_digit.c ft_printf_hexa.c
SRCS			= ${SRC}
OBJS			= ${SRCS:.c=.o}
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

.c.o:
				$(CC) -I. $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
				ar rcs $(NAME) $?
				ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)