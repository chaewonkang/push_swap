# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 16:34:42 by ljoly             #+#    #+#              #
#    Updated: 2017/07/05 21:04:23 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker

SRCS = get_specs.c get_min_med_max.c push_swap.c op.c simple_sort.c \
	  next_target.c quick_sort.c is_sorted.c store_op.c rm_doubles.c end.c \
	  display.c

SRCS_C = checker.c checker_op.c is_sorted.c end.c

FLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/
HEADER = ./includes/
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
	@gcc $(FLAGS) -o $(NAME) -I $(HEADER) $(OBJ) -L $(LIBFT) -lft
	@echo "$(GREEN)[✓]$(NC) Executable $(NAME) ready!"

$(NAME_C): $(OBJ_C)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -o $(NAME_C) -I $(HEADER) $(OBJ_C) -L $(LIBFT) -lft
	@echo "$(GREEN)[✓]$(NC) Executable $(NAME_C) ready!"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(LIBFT) -I $(HEADER) -o $@ -c $<
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

.PHONY: all clean fclean re
