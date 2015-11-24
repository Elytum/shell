#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 22:41:37 by achazal           #+#    #+#              #
#    Updated: 2015/01/28 22:41:42 by achazal          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all, clean, fclean, mrproper, re, fast, .SILENT

CC = clang
NAME = htable.a
CFLAGS = -Wall -Werror -Wextra -pedantic -I./ -Xclang -fcolor-diagnostics -O3
SOURCE = htable.c

OBJ = $(SOURCE:.c=.o)


ifeq ($(FAST), 1)
	CFLAGS := -O3 $(CFLAGS)
else
	CFLAGS := -O2 $(CFLAGS)
endif


all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[31;1m• \033[0mCreating archive $@ ...\033[55G\c"
	@export result=`ar rcs $@ $(OBJ) 2>&1` ; \
	if [ "$$result" = "" ] ; then \
		echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m" ; \
	else \
		echo "\033[37;1m[\033[31mFAIL\033[37m]\033[0m" ; \
		echo "\n$$result" ; \
		exit 1 ; \
	fi

ifeq ($(FAST), 1)

%.o : %_fast.c libft.h
	@echo "\033[31;1m• \033[0mCreating object file $@ ...\033[55G\c"
	@export result=`$(CC) $(CFLAGS) -c $< -o $@ 2>&1` ; \
	if [ "$$result" = "" ] ; then \
		echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m" ; \
	else \
		echo "\033[37;1m[\033[31mFAIL\033[37m]\033[0m" ; \
		echo "\n$$result" ; \
		exit 1 ; \
	fi
endif


%.o : %.c libft.h
	@echo "\033[31;1m• \033[0mCreating object file $@ ...\033[55G\c"
	@export result=`$(CC) $(CFLAGS) -c $< -o $@ 2>&1` ; \
	if [ "$$result" = "" ] ; then \
		echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m" ; \
	else \
		echo "\033[37;1m[\033[31mFAIL\033[37m]\033[0m" ; \
		echo "\n$$result" ; \
		exit 1 ; \
	fi

fast:
	@make -C . FAST=1

clean :
	@echo "\033[31;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@echo "\033[31;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

mrproper: fclean

re : fclean all

.SILENT: