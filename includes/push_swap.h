/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:54:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/22 19:50:36 by ljoly            ###   ########.fr       */
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
# define TAB env->tab
# define PARAM env->param
# define LEN_A env->len_a
# define LEN_B env->len_b
# define I env->index_i
# define J env->index_j
# define OP_OK env->op_ok
# define DISPLAY env->display_stacks
# define MED env->med
# define MED_RANK env->med_rank
# define MED_B env->med_b
# define DIST env->dist
# define MIN env->min
# define MAX env->max
# define MAX_B env->max_b
# define IS_SORT_A env->is_sort_a

/*
** Counting algorithms' moves to choose the fastest
*/
# define MOVES env->moves

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

typedef	struct s_med	t_med;

struct					s_med
{
	int					rank;
	char				med;
	t_med				*next;
};

/*
** Storing environment - both programs will use a 't_stack' type
*/
typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			*tab;
	int			param;
	int			len_a;
	int			len_b;
	int			index_i;
	int			index_j;
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
int				get_operations(char *line, t_stack *env);

/*
** Non-static functions for push_swap
*/
void			get_min_med_max(t_stack *env);
int				get_med(int *st, int len);
int				get_min(int *st, int len);
int				get_max(int *st, int len);
void			push_swap(t_stack *env);
int				*bubble_sort(int *st, int len);
void			simple_sort(t_stack *env, int min, int max);
void			few_values_sort(t_stack *env);
int				next_target(int *st, int len, int target, int comp);
void			quick_sort(t_stack *env);
int				is_not_ranked(t_stack *env, int inc);
void			shift_a(t_stack *env, int len, int rank, int pb);
void			do_op(t_stack *env, int op);
void			send_op(t_stack *env, int op);

/*
** Non-static functions for both programs
*/
int				is_sort(int *st, int len, int start, int inc);
int				ft_end(int status, t_stack *env);

#endif
