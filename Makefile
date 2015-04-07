# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/26 21:48:45 by etermeau          #+#    #+#              #
#    Updated: 2015/02/26 21:48:52 by etermeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

LIB = libft/

HEADER = includes/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  ft_command.c \
	  ft_list.c \
	  ft_singleton.c \
	  ft_print.c \
	  ft_lexer.c \
	  ft_lexer_list.c \
	  ft_parser.c \
	  ft_init_tab.c \
	  ft_erreur.c \
	  ft_fork.c \
	  ft_get.c \
	  ft_builtin_cd.c \
	  ft_access_cd.c \
	  ft_new_env.c \
	  ft_builtin_env.c \
	  ft_setenv.c \
	  ft_builtin_exit.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft -g
	@echo "\033[5;32m$(NAME) Successfully $(STATE)\033[0m"

%.o: $(DIRSRC)%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)

re: fclean all
