# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	42sh
MYPATH	=	$(HOME)
#--------------Sources----------------------#
SRCS	=	main.c						\
			\
			execution/fill_binaries.c	\
			execution/launch_command.c	\
			execution/tools.c			\
			\
			builtins/init.c				\
			builtins/builtins_tools.c	\
			builtins/alias.c			\
			builtins/cd.c				\
			builtins/echo.c				\
			builtins/env.c				\
			builtins/exit.c				\
			builtins/setenv.c			\
			builtins/unalias.c			\
			builtins/unsetenv.c			\
			builtins/which.c

INC		=	-I./ -I./includes -I./execution -I./builtins -I./htable -I./interpretation
LIBS	=	htable/htable.a interpretation/interpretation.a
CCFLAGS	=	-Wall -Wextra -Werror -g

OBJS	=	$(SRCS:.c=.o)

#--------------Actions----------------------#

.PHONY: LIBRARIES $(NAME) clean fclean re test

all: $(NAME)

LIBRARIES:
	@make -C interpretation
	@make -C htable

$(NAME): LIBRARIES $(OBJS)
	$(CC) $(CCFLAGS) $(INC) $(OBJS) -o $(NAME) $(LIBS) -O3

%.o: %.c
	@$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	@make clean -C interpretation
	@make clean -C htable
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all
	make
