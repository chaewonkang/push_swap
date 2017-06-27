/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/16 20:15:47 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		targets_hierarchy(t_stack *e, int rank_up, int rank_down)
{
	int			up_dist;
	int			down_dist;

	up_dist = (rank_up < LEN_A - rank_up ? rank_up : LEN_A - rank_up);
	down_dist = (rank_down < LEN_A - rank_down ? rank_down : LEN_A - rank_down);
	return (up_dist < down_dist ? rank_up : rank_down);
}

static void		proceed_op(t_stack *e, int op)
{
	do_op(e, op);
	send_op(e, op);
}

static void		push_b(t_stack *e)
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
		first = targets_hierarchy(e, rank_up, rank_down);
		ft_printf("FIRST = %d\n", first);
		if (B[0] < B[1] && first > 0 && first < LEN_A / 2 && (diff = 1))
		{
			ft_putendl("PREMIER");
			proceed_op(e, RR);
		}
		else if (B[0] < B[1])
			proceed_op(e, RB);
		shift_a(e, LEN_A, first - diff, 1);
		proceed_op(e, PB);
		diff = 0;
		second = next_target(A, LEN_A, first == rank_up ? TAB[J] : TAB[I], 2);
		ft_printf("TARGET = %d\nSECOND = %d\n", first == rank_up ? TAB[J] : TAB[I], second);
		if (B[0] < B[1] && second > 0 && second < LEN_A / 2 && (diff = 1))
		{
			ft_putendl("DEUXIEME");
			proceed_op(e, RR);
		}
		else if (B[0] < B[1])
			proceed_op(e, RB);
		shift_a(e, LEN_A, second - diff, 1);
		do_op(e, PB);
		send_op(e, PB);
	}
}	

void		quick_sort(t_stack *e)
{
	int		rank;

	rank = next_target(A, LEN_A, MED, 2);
	shift_a(e, LEN_A, rank, 1);
	proceed_op(e, PB);
	I = MED_RANK;
	J = MED_RANK;
	push_b(e);
	if (B[0] < B[1])
		proceed_op(e, RB);
	proceed_op(e, PB);
	proceed_op(e, RB);
	while (LEN_B > 0)
		proceed_op(e, PA);
}
