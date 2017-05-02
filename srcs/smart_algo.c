/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:51:47 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/02 16:09:21 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		move(t_stack *env, int start, int end, int op)
{
	I = start - 1;
	while (++I <= end)
	{
		do_op(env, op);
		store_op(env, op, 0);
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

static void		sort_a(t_stack *env)
{
	int			op;

	op = 0;
	if (A[0] > A[1] && A[0] > A[LEN_A - 1] && A[0] - A[1] < A[0] - A[LEN_A - 1]) &&
		|| (op = SA)
			operate(env, SA);
}

static void		use_b(t_stack *env)
{
	int			op;

	op = 0;
	if (!(I = next_target(A, LEN_A, MED)) && (op = PB))
		operate(env, PB);
	else if (LEN_B > 1 && A[0] > A[1] && B[0] < B[1] && (op = SS))
		operate(env, SS);
	else if (I > -1 && I <= MED_RANK && LEN_B > 1 && B[0] < B[LEN_B - 1])
		operate(env, RR);
	else if (I > MED_RANK && LEN_B > 1 && B[0] < B[LEN_B - 1])
		operate(env, RRR);
	else if (LEN_B > 1 && B[0] < B[1] && (op = SB))
		operate(env, SB);
	else if ((I == 1 || (A[0] > A[1] && A[0] > A[LEN_A - 1] &&
					A[0] - A[1] < A[0] - A[LEN_A - 1])) && (op = SA))
		operate(env, SA);
	else if (I > -1 && I <= MED_RANK)
		move(env, 0, I, RA);
	else if ((I > -1 && I > MED_RANK) || A[0] > A[LEN_A - 1])
		move(env, I, LEN_A, RRA);
	else if (LEN_B > 1 && B[0] > B[1] && B[0] > B[LEN_B - 1] &&
			B[0] - B[1] < B[0] - B[LEN_B - 1] && (op = RB))
		operate(env, RB);
	else if (((LEN_B > 1 && B[0] > B[1] && B[0] > B[LEN_B - 1] &&
					B[0] - B[1] > B[0] - B[LEN_B - 1]) ||
				(LEN_B > 1 && B[0] > B[1] && B[0] < B[LEN_B - 1])) && (op = RRB))
		operate(env, RRB);
	op ? store_op(env, op, 0) : (op = 1) ;
}

void		smart_push_swap(t_stack *env)
{
	int		med_rank;

	med_rank = ((MED_RANK == PARAM / 2) ? MED_RANK : MED_RANK);
	if (LEN_A > 3)
	{
		while (LEN_B < med_rank || !is_sort(B, LEN_B, 0))
		{
			(LEN_B < med_rank) ? ft_putendl("LEN_B < MED_RANK") : ft_putendl("!is_sort");
			use_b(env);
		}
	}
	while (!is_sort(A, LEN_A, 1))
	{
		ft_putendl("TAMERE");
		sort_a(env);
	}
	while (LEN_B > 0)
	{
		operate(env, PA);
		store_op(env, PA, 0);
	}
}
