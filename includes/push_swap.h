/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:54:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/04 18:56:13 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

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
	char			op;
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
	char		op_ok;
	int			med;
	int			dist;
	int			min;
	int			max;
	char		first_round;
	t_op		**op;
	int			moves;
	char		display_stacks;
}				t_stack;

/*
** Non-static function for checker
*/
int				get_operations(char *line, t_stack *e);

/*
** PUSH_SWAP
*/
void			push_swap(t_stack *e);

/*
** Get stacks' features
*/
int				get_med(int *st, int len);
int				get_min(int *st, int len);
int				get_max(int *st, int len);
int				get_next_med(t_stack *e, int *st, int size);
int				get_dist_to_med(int *st, int size, int next_med);
int				is_not_ranked(t_stack *e, int *st, int len);
int				is_sorted(int *st, int len, int start, int inc);

/*
** Two sorting algorithms
*/
void			simple_sort(t_stack *e);
void			quick_sort(t_stack *e);

int				next_target(int *st, int len, int target, char comp);
void			do_op(t_stack *e, char op);
void			send_op(t_stack *e, char op);
void			proceed_op(t_stack *e, char op, int store);
void			store_op(t_stack *e, char op);

int				ft_end(int status);

#endif
