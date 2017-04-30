/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:03:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/29 19:02:15 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		is_sort(int *st, int len, int inc)
{
	int			i;

	i = -1;
	if (inc)
	{
		while (++i + 1 < len)
		{
			if (st[i] >= st[i + 1])
				return (0);
		}
		return (1);
	}
	else
	{
		while (++i + 1 < len)
		{
			if (st[i] <= st[i + 1])
				return (0);
		}
		return (1);
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
	return (INT_MIN);
}

static void		put_to_b(t_stack *env)
{
	int			index;
	int			op;

	index = next_target(A, LEN_A, MED);
	if (!index && (op = PB))
		operate(env, PB);
	else if (index <= MED_RANK)
	{
		I = -1;
		while (index <= MED_RANK && ++I < index && (op = RA))
		{
			operate(env, RA);
			send_instruction(op);
		}
	}
	else if (index > MED_RANK)
	{
	}
	else if (A[1] < MED && (op == SA))
		operate(env, SA);
}

void			push_swap(t_stack *env)
{
	int			op;

	if (LEN_A > 3)
	{
		while (LEN_B < MED_RANK || !is_sort(B, LEN_B, 0))
			put_to_b(env);
	}
	while (LEN_A < PARAM || !is_sort(A, LEN_A, 1))
	{
		if (A[0] > A[LEN_A - 1] && A[0] > A[1] &&
			A[0] - A[1] < A[0] - A[LEN_A - 1] && (op = SA))
			operate(env, SA);
//		if (LEN_A > 1 && LEN_B > 1 && A[0] > A[1] && B[0] > B[1] && (op = SS))
//			operate(env, SS);
//		else if (LEN_A > 1 && A[0] > A[1] && (op = SA))
//			operate(env, SA);
		send_instruction(op);
	}
	while (LEN_B > 0)
	{
		operate(env, PB);
		send_instruction(PB);
	}
}
