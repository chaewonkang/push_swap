/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/12 19:06:59 by ljoly            ###   ########.fr       */
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

static void		push_b(t_stack *env)
{
	int			rank_up;
	int			rank_down;
	int			first;
	int			second;

	ft_printf("LEN_A = %d\nTAB[I + 1] = %d\nTAB[J - 1] = %d\n", LEN_A, TAB[I + 1], TAB[J - 1]);
	while (LEN_A > 0 && TAB[++I] < PARAM && TAB[--J] > 0)
	{
		ft_putendl("OUAIS");
		rank_up = next_target(A, LEN_A, TAB[I], 2);
		rank_down = next_target(A, LEN_A, TAB[J], 2);
		first = targets_hierarchy(env, rank_up, rank_down);
		shift_a(env, LEN_A, first, 1);
		do_op(env, PB);
		send_op(env, PB);
		second = next_target(A, LEN_A, first == rank_up ? TAB[J] : TAB[I], 2);
		shift_a(env, LEN_A, second, 1);
		do_op(env, PB);
		send_op(env, PB);
	}
}	

void		quick_sort(t_stack *env)
{
	int		rank;

	rank = next_target(A, LEN_A, MED, 2);
	shift_a(env, LEN_A, rank, 1);
	do_op(env, PB);
	send_op(env, PB);
	I = MED_RANK;
	J = MED_RANK;
	ft_putendl("SAMERE");
	push_b(env);
	//ensuite PA;
}
