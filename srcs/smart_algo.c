/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:51:47 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/05 17:16:13 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
static void     	shift_b(t_stack *env, int len, int rank)
{
	if (rank < LEN_B / 2)
	{
		while (rank > 0)
		{
			do_op(env, RB);
			send_op(env, RB);
			rank--;
		}
	}
	else
	{
		while (rank + 1 < len)
		{
			do_op(env, RRB);
			send_op(env, RRB);
			rank++;
		}
	}
}

static void		shift_both(t_stack *env, int rank_a, int rank_b)
{
	int		rank;
	int		len;

	if (!(rank_a < LEN_A / 2 && rank_b < LEN_B / 2) &&
		!(rank_a >= LEN_A / 2 && rank_b >= LEN_B / 2))
		return ;
	if (rank_a < LEN_A / 2 && rank_b < LEN_B / 2)
	{
		rank = (rank_a < rank_b ? rank_a : rank_b);
		while (rank > 0)
		{
			do_op(env, RR);
			send_op(env, RR);
			rank--;
		}
	}
	else
	{
		rank = (rank_a > rank_b ? rank_a : rank_b);
		len = (rank_a > rank_b ? LEN_A : LEN_B);
		while (rank + 1 < len)
		{
			do_op(env, RRR);
			send_op(env, RRR);
			rank++;
		}
	}
}

static int		next_target(int *st, int len, int target)
{
	int			i;
	int			j;

	i = -1;
	j = len;
	while (++i < len && --j > i)
	{
		if (st[i] < target)
			return (i);
		else if (st[j] < target)
			return (j);
	}
	return (-1);
}

static void		use_b(t_stack *env)
{
	int			op;
	int			rank_a;
	int			rank_b;

	op = 0;
	rank_a = -1;
	rank_b = -1;
	if (!IS_SORT_A && !(I = next_target(A, LEN_A, MED)) && (op = PB))
		do_op(env, PB);
	else if ((rank_a = is_not_ranked(env, 1)) > 0 && (rank_b = is_not_ranked(env, 0)) > 0)
		shift_both(env, rank_a, rank_b);
	else if (rank_a > 0)
		shift_a(env, LEN_A, rank_a);
	else if (rank_b > 0)
		shift_b(env, LEN_B, rank_b);
	else if (!IS_SORT_A && LEN_B > 1 && ((A[0] != MAX && A[0] > A[1]) ||
		(A[0] == MED && A[1] == MAX)) && ((B[0] != MIN &&
		B[0] < B[1]) || (B[0] == MAX_B && B[1] == MIN)) && (op = SS))
		do_op(env, SS);
	else if (!IS_SORT_A && ((A[0] != MAX && A[0] > A[1]) || (A[0] == MED && A[1] == MAX)) && (op = SA))
		do_op(env, SA);
	else if (LEN_B > 1 && ((B[0] != MIN && B[0] < B[1]) || (B[0] == MAX_B && B[1] == MIN)) && (op = SB))
		do_op(env, SB);
	else if ((op = RR))
		do_op(env, RR);
	if (op)
		send_op(env, op);*/
/*	else if (LEN_B > 1 && A[0] > A[1] && B[0] < B[1] && (op = SS))
		do_op(env, SS);
	else if (I > -1 && I <= MED_RANK && LEN_B > 1 && B[0] < B[LEN_B - 1])
		do_op(env, RR);
	else if (I > MED_RANK && LEN_B > 1 && B[0] < B[LEN_B - 1])
		do_op(env, RRR);
	else if ((LEN_B > 1 && B[0] < B[1] && B[0] < A[LEN_B - 1] &&
				B[0] - B[1] > B[LEN_B - 1]) && (op = SB))
		do_op(env, SB);
	else if ((I == 1 || (A[0] > A[1] && A[0] > A[LEN_A - 1] &&
					A[0] - A[1] < A[0] - A[LEN_A - 1])) && (op = SA))
		do_op(env, SA);
	else if (I > -1 && I <= MED_RANK && (op = RA))
		do_op(env, RA);
	//move(env, 0, I, RA);
	else if (((I > -1 && I > MED_RANK) || A[0] > A[LEN_A - 1]) && (op = RRA))
		do_op(env, RRA);
	//move(env, I, LEN_A, RRA);
	else if (LEN_B > 1 && B[0] > B[1] && B[0] > B[LEN_B - 1] &&
			B[0] - B[1] < B[0] - B[LEN_B - 1] && (op = RB))
		do_op(env, RB);
	else if (((LEN_B > 1 && B[0] > B[1] && B[0] > B[LEN_B - 1] &&
					B[0] - B[1] > B[0] - B[LEN_B - 1]) ||
				(LEN_B > 1 && B[0] > B[1] && B[0] < B[LEN_B - 1])) && (op = RRB))*/
//		do_op(env, RRB);
	//	op ? store_op(env, op, 0) : (op = 1) ;
//}

//RECALCULER MAX_B
//PB D'AFFICHAGE DE LA STACK_B
void		smart_push_swap(t_stack *env)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		do_op(env, PB);
		send_op(env, PB);
		i++;
	}

/*	while (LEN_B < MED_RANK - 1 || !is_sort(B, LEN_B, 0, 0))
	{
		if (is_sort(A, LEN_A, 0, 1) && (IS_SORT_A = 1))
			break;
		(LEN_B < MED_RANK - 1) ? ft_putendl("LEN_B < MED_RANK") : ft_putendl("!is_sort");
		use_b(env);
	}
	while (!is_sort(B, LEN_B, 0, 0))
		use_b(env);
	if (!IS_SORT_A)
		idiot_push_swap(env, MED, MAX);
	while (LEN_B > 0)
	{
		do_op(env, PA);
//		store_op(env, PA, 0);
		send_op(env, PA);
	}*/
}
