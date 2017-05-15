/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/15 16:46:47 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
//CHECKER LE DEGRE DE DIFF
static int		ft_comp(t_stack *env)
{
	MIN = get_min(A, LEN_A);


}*/

static int		targets_hierarchy(t_stack *env, int rank_up, int rank_down)
{
	int			up_dist;
	int			down_dist;

	up_dist = (rank_up < LEN_A - rank_up ? rank_up : LEN_A - rank_up);
	down_dist = (rank_down < LEN_A - rank_down ? rank_down : LEN_A - rank_down);
	return (up_dist < down_dist ? rank_up : rank_down);
}

static void		proceed_op(t_stack *env, int op)
{
	do_op(env, op);
	send_op(env, op);
}

static void		push_b(t_stack *env)
{
	int			rank_up;
	int			rank_down;
	int			first;
	int			second;
	int			diff;

	while (LEN_A > 0 && ++I < PARAM && --J >= 0)
	{
		diff = 0;
		rank_up = next_target(A, LEN_A, TAB[I], 2);
		rank_down = next_target(A, LEN_A, TAB[J], 2);
		ft_printf("RANK_UP = %d\nRANK_DOWN = %d\n", rank_up, rank_down);
		first = targets_hierarchy(env, rank_up, rank_down);
		ft_printf("FIRST = %d\n", first);
		if (B[0] < B[1] && first > 0 && first < LEN_A / 2 && (diff = 1))
		{
			ft_putendl("PREMIER");
			proceed_op(env, RR);
		}
		else if (B[0] < B[1])
			proceed_op(env, RB);
		shift_a(env, LEN_A, first - diff, 1);
		proceed_op(env, PB);
		diff = 0;
		second = next_target(A, LEN_A, first == rank_up ? TAB[J] : TAB[I], 2);
		ft_printf("TARGET = %d\nSECOND = %d\n", first == rank_up ? TAB[J] : TAB[I], second);
		if (B[0] < B[1] && second > 0 && second < LEN_A / 2 && (diff = 1))
		{
			ft_putendl("DEUXIEME");
			proceed_op(env, RR);
		}
		else if (B[0] < B[1])
			proceed_op(env, RB);
		shift_a(env, LEN_A, second - diff, 1);
		do_op(env, PB);
		send_op(env, PB);
	}
}	

void		quick_sort(t_stack *env)
{
	int		rank;

	rank = next_target(A, LEN_A, MED, 2);
	shift_a(env, LEN_A, rank, 1);
	proceed_op(env, PB);
	I = MED_RANK;
	J = MED_RANK;
	push_b(env);
	if (B[0] < B[1])
		proceed_op(env, RB);
	proceed_op(env, PB);
	proceed_op(env, RB);
	while (LEN_B > 0)
		proceed_op(env, PA);
}
