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
	int			op_ok;
	int			med;
	int			dist;
	int			min;
	int			max;
	int			moves;
	int			display_stacks;
}				t_stack;

/*
** Non-static function for checker
*/
int				get_operations(char *line, t_stack *e);

/*
** PUSH_SWAP
*/
void			push_swap(t_stack *e);

int				get_med(int *st, int len);
int				get_min(int *st, int len);
int				get_max(int *st, int len);
int				get_next_med(t_stack *e, int *st, int size);
int				get_dist_to_med(int *st, int size, int next_med);
void			simple_sort(t_stack *e);
int				next_target(int *st, int len, int target, int comp);
void			quick_sort(t_stack *e);
int				is_not_ranked(t_stack *e, int *st, int len);
void			do_op(t_stack *e, int op);
void			send_op(t_stack *e, int op);
void			proceed_op(t_stack *e, int op);

/*
** Non-static functions for both programs
*/
int				is_sort(int *st, int len, int start, int inc);
int				ft_end(int status);

#endif
