/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:54:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/18 19:05:56 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define A stack->stack_a
# define B stack->stack_b
# define PARAM stack->param
# define LEN_A stack->len_a
# define LEN_B stack->len_b
# define I stack->i
# define J stack->j

typedef struct	s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	param;
	int	len_a;
	int	len_b;
	int	i;
	int	j;
}		t_stack;

int		get_instructions(char *line, t_stack *stack);
int		ft_end(int status);

#endif
