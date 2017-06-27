/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_values_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:15:12 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/21 20:31:53 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void     	shift_b(t_stack *e, int len, int rank)
{
	ft_putendl("SHIFT_B");
	if (rank < LEN_B / 2)
	{
		while (rank > 0)
		{
			do_op(e, RB);
			send_op(e, RB);
			rank--;
		}
	}
	else
	{
		while (rank + 1 < len)
		{
			do_op(e, RRB);
			send_op(e, RRB);
			rank++;
		}
	}
}

static void		shift_both(t_stack *e, int rank_a, int rank_b, int pb)
{
	int		rank;
	int		len;

	ft_putendl("SHIFT_BOTH");
	if (rank_a < LEN_A / 2 && rank_b < LEN_B / 2)
	{
		rank = (rank_a < rank_b ? rank_a : rank_b);
		while (rank > 0)
		{
			do_op(e, RR);
			send_op(e, RR);
			rank--;
		}
	}
	else
	{
		if (pb)
			rank_a--;
		rank = (rank_a > rank_b ? rank_a : rank_b);
		len = (rank_a > rank_b ? LEN_A : LEN_B);
		while (rank + 1 < len)
		{
			do_op(e, RRR);
			send_op(e, RRR);
			rank++;
		}
	}
}

int				next_target(int *st, int len, int target, int comp)
{
	int			i;
	int			j;

	i = -1;
	j = len;
	if (comp == 1)
	{
		while (++i < len && --j > i)
		{
			if (st[i] < target)
				return (i);
			else if (st[j] < target)
				return (j);
		}
	}
	else if (comp == 2)
	{
		while (++i < len && --j >= i)
		{
			if (st[i] == target)
				return (i);
			else if (st[j] == target)
				return (j);
		}
	}
	return (-1);
}

static void     use_b(t_stack *e)
{
	int         op;
	int         rank_a;
	int         rank_b;

	I = -1;
	op = 0;
	rank_a = -1;
	rank_b = -1;
	if (!IS_SORT_A && !(I = next_target(A, LEN_A, MED, 1)) && (op = PB))
		do_op(e, PB);
	else if (!IS_SORT_A && I > 0)
		shift_a(e, LEN_A, I, 1);
	else if ((rank_a = is_not_ranked(e, 1)) > 0 &&
			(rank_b = is_not_ranked(e, 0)) > 0 && ((rank_a < LEN_A / 2 &&
					rank_b < LEN_B / 2) || (rank_a >= LEN_A / 2 &&
						rank_b >= LEN_B / 2)))
		shift_both(e, rank_a, rank_b, 0);
	else if (rank_a > 0)
		shift_a(e, LEN_A, rank_a, 0);
	else if ((rank_b = is_not_ranked(e, 0)) > 0)
		shift_b(e, LEN_B, rank_b);
	else if (!IS_SORT_A && LEN_B > 1 && ((A[0] != MAX && A[0] > A[1]) ||
				(A[0] == MED && A[1] == MAX)) && ((B[0] != MIN &&
						B[0] < B[1]) || (B[0] == MAX_B && B[1] == MIN)) && (op = SS))
		do_op(e, SS);
	else if (!IS_SORT_A && ((A[0] != MAX && A[0] > A[1]) || (A[0] == MED && A[1] == MAX)) && (op = SA))
		do_op(e, SA);
	else if (LEN_B > 1 && ((B[0] != MIN && B[0] < B[1]) || (B[0] == MAX_B && B[1] == MIN)) && (op = SB))
		do_op(e, SB);
	else if (!IS_SORT_A && !is_sort(B, LEN_B, 0, 0) && (op = RR))
		do_op(e, RR);
	else if (!IS_SORT_A && (op = RA))
		do_op(e, RA);
	else if ((op = RB))
		do_op(e, RB);
	if (op)
		send_op(e, op);
}

void		few_values_sort(t_stack *e)
{
	while (LEN_B < MED_RANK - 1 || !is_sort(B, LEN_B, 0, 0))
	{
		if (!IS_SORT_A && is_sort(A, LEN_A, 0, 1) && (IS_SORT_A = 1))
			break;
		(LEN_B < MED_RANK - 1) ? ft_putendl("LEN_B < MED_RANK") : ft_putendl("!is_sort");
		use_b(e);
	}
	while (!is_sort(B, LEN_B, 0, 0))
		use_b(e);
	if (!IS_SORT_A)
		simple_sort(e, MED, MAX);
	while (LEN_B > 0)
	{
		do_op(e, PA);
		send_op(e, PA);
		//		store_op(e, PA, 0);
		while (!is_sort(A, LEN_A, 0, 1))
			simple_sort(e, MED, MAX);
	}
}
