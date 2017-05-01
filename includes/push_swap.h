/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:54:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/01 19:30:45 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

/*
** Defining environment features
*/
# define A env->stack_a
# define B env->stack_b
# define PARAM env->param
# define LEN_A env->len_a
# define LEN_B env->len_b
# define I env->index_i
# define J env->index_j
# define OP_OK env->op_ok
# define DISPLAY env->display_stacks
# define MED env->med
# define MED_RANK env->med_rank
# define DIST env->dist
# define MIN env->min
# define MAX env->max

/*
** Defining instructions for push_swap
*/
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

/*
** Storing environment - both programs will use a 't_stack' type
*/
typedef struct	s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		param;
	int		len_a;
	int		len_b;
	int		index_i;
	int		index_j;
	int		op_ok;
	int		display_stacks;
	int		med;
	int		med_rank;
	int		dist;
	int		min;
	int		max;
}				t_stack;

/*
** Non-static functions for checker
*/
int				get_operations(char *line, t_stack *env);

/*
** Non-static functions for push_swap
*/
void			push_swap(t_stack *env);
void			operate(t_stack *env, int op);
void			send_instruction(t_stack *env, int op);

/*
** Non-static functions for both programs
*/
int				is_sort(int *st, int len, int inc);
int				ft_end(int status, t_stack *env);

#endif
