/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:54:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/28 14:42:56 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

/*
** Defining environment features
*/
# define A e->stack_a
# define B e->stack_b
# define PARAM e->param
# define LEN_A e->len_a
# define LEN_B e->len_b
# define I e->i
# define J e->j
# define OP_OK e->op_ok
# define MED e->med
# define MED_RANK e->med_rank
# define MED_B e->med_b
# define DIST e->dist
# define MIN e->min
# define MAX e->max
# define MAX_B e->max_b
# define IS_SORT_A e->is_sort_a
# define MOVES e->moves

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

typedef	struct s_op	t_op;

struct				s_op
{
	int			op;
	t_op			*prev;
	t_op			*next;
};

/*
** Storing environment - both programs will use a 't_stack' type
*/
typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			*tab_med;
	int			param;
	int			len_a;
	int			len_b;
	int			i;
	int			j;
	int			op_ok;
	int			med;
	int			med_rank;
	int			med_b;
	int			dist;
	int			min;
	int			max;
	int			max_b;
	int			moves;
	int			is_sort_a;
	int			display_stacks;
}				t_stack;

/*
** Non-static functions for checker
*/
int				get_operations(char *line, t_stack *e);

/*
** Non-static functions for push_swap
*/
void			get_min_med_max(t_stack *e);
int				get_med(int *st, int len);
int				get_min(int *st, int len);
int				get_max(int *st, int len);
void			push_swap(t_stack *e);
int				*bubble_sort(int *st, int len);
void			simple_sort(t_stack *e, int min, int max);
void			few_values_sort(t_stack *e);
int				next_target(int *st, int len, int target, int comp);
void			quick_sort(t_stack *e);
int				is_not_ranked(t_stack *e, int inc);
void			shift_a(t_stack *e, int len, int rank, int pb);
void			do_op(t_stack *e, int op);
void			send_op(t_stack *e, int op);
void			proceed_op(t_stack *e, int op);

/*
** Non-static functions for both programs
*/
int				is_sort(int *st, int len, int start, int inc);
int				ft_end(int status);

#endif
