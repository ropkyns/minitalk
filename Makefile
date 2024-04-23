# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 15:54:37 by paulmart          #+#    #+#              #
#    Updated: 2024/04/23 18:34:11 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C				= client.c
SRC_S				= server.c
SRCS_C				= $(addprefix ./source/, $(SRC_C))
SRCS_S				= $(addprefix ./source/, $(SRC_S))

SRC_CB				= client_bonus.c
SRC_SB				= server_bonus.c
SRCS_CB				= $(addprefix ./source/, $(SRC_CB))
SRCS_SB				= $(addprefix ./source/, $(SRC_SB))

OBJS_C				= $(SRCS_C:.c=.o)
OBJS_S				= $(SRCS_S:.c=.o)

OBJS_CB			= $(SRCS_CB:.c=.o)
OBJS_SB			= $(SRCS_SB:.c=.o)

SRC_DIR				= source/
CC					= cc
FLAGS				= -Wextra -Werror -Wall
NAME_C				= client
NAME_S				= server
NAME_CB				= client_bonus
NAME_SB				= server_bonus
PRINTF_DIR			= ft_printf
PRINTF				= ft_printf/libftprintf.a
RM					= rm -f
HEADER				= -I inc

start:
					$(MAKE) -C $(PRINTF_DIR)

all:				$(NAME_C) $(NAME_S)

$(NAME_C):			$(OBJS_C)
							$(CC) $(FLAGS) $(OBJS_C) $(HEADER) $(PRINTF) -o $(NAME_C)

$(NAME_S):			$(OBJS_S)
							$(CC) $(FLAGS) $(OBJS_S) $(HEADER) $(PRINTF) -o $(NAME_S)

bonus:				$(NAME_CB) $(NAME_SB)

$(NAME_CB):			$(OBJS_CB)
							$(CC) $(FLAGS) $(OBJS_CB) $(HEADER) $(PRINTF) -o $(NAME_CB)

$(NAME_SB):			$(OBJS_SB)
							$(CC) $(FLAGS) $(OBJS_SB) $(HEADER) $(PRINTF) -o $(NAME_SB)

clean:
							$(RM) $(OBJS_C) $(OBJS_S) $(OBJS_CB) $(OBJS_SB)
							$(MAKE) clean -C (PRINTF_DIR)

fclean:				clean
							$(RM) $(NAME_C) $(NAME_S) $(NAME_CB) $(NAME_SB)
							$(MAKE) fclean -C $(PRINTF_DIR)

re:					fclean
							$(MAKE) start
							$(MAKE) all

norminette:
							@clear
							@norminette

.PHONY:				start all bonus clean fclean re norminette