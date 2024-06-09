# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 15:54:37 by paulmart          #+#    #+#              #
#    Updated: 2024/06/03 16:12:55 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C				= client.c
SRC_S				= server.c
SRCS_C				= $(addprefix ./source/, $(SRC_C))
SRCS_S				= $(addprefix ./source/, $(SRC_S))

OBJS_C				= $(SRCS_C:.c=.o)
OBJS_S				= $(SRCS_S:.c=.o)

SRC_DIR				= source/
CC					= cc
FLAGS				= -Wextra -Werror -Wall
NAME_C				= client
NAME_S				= server
PRINTF_DIR			= ft_printf
PRINTF				= ft_printf/libftprintf.a
RM					= rm -f
HEADER				= -I inc

all:				start $(NAME_C) $(NAME_S)

start:
					$(MAKE) -C $(PRINTF_DIR)

$(NAME_C):			$(OBJS_C)
							$(CC) $(FLAGS) $(OBJS_C) $(HEADER) $(PRINTF) -o $(NAME_C)

$(NAME_S):			$(OBJS_S)
							$(CC) $(FLAGS) $(OBJS_S) $(HEADER) $(PRINTF) -o $(NAME_S)


clean:
							$(RM) $(OBJS_C) $(OBJS_S)
							$(MAKE) clean -C $(PRINTF_DIR)

fclean:				clean
							$(RM) $(NAME_C) $(NAME_S)
							$(MAKE) fclean -C $(PRINTF_DIR)

re:					fclean
							$(MAKE) start
							$(MAKE) all

norminette:
							@clear
							@norminette

.PHONY:				start all clean fclean re norminette
