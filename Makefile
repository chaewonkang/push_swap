# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 16:34:42 by ljoly             #+#    #+#              #
#    Updated: 2017/04/18 17:23:48 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker

SRCS = main_push_swap.c
SRCS_C = checker.c end.c operations.c

FLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/
HEADER = ./includes
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
OBJ_C = $(addprefix $(OBJ_PATH), $(SRCS_C:.c=.o))
OBJ_PATH = ./obj/
SRCS_PATH = ./srcs/

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME) $(NAME_C)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -lft
	@echo "$(GREEN)[✓]$(NC) Executable $(NAME) ready!"

$(NAME_C): $(OBJ_C)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -o $(NAME_C) $(OBJ_C) -L $(LIBFT) -lft
	@echo "$(GREEN)[✓]$(NC) Executable $(NAME_C) ready!"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(LIBFT) -o $@ -c $<
	@echo "$(GREEN)[✓]$(NC) Compiling" $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[-]$(NC) Objects cleaned..."

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@echo "$(RED)[-]$(NC) Executable $(NAME) cleaned..."
	@rm -f $(NAME_C)
	@echo "$(RED)[-]$(NC) Executable $(NAME_C) cleaned..."

re: fclean all

.PHONY: $(NAME) all clean fclean re
