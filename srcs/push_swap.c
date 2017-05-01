/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:03:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/01 20:12:39 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		move(t_stack *env, int start, int end, int op)
{
	I = start - 1;
	while (++I <= end)
	{
		operate(env, op);
		send_instruction(env, op);
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

//static void		sort_a(t_stack *env)
//{
//}

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
	op ? send_instruction(env, op) : (op = 1) ;
}

void			push_swap(t_stack *env)
{

	if (LEN_A > 3)
	{
		while (LEN_B < MED_RANK || !is_sort(B, LEN_B, 0))
		{
			LEN_B < MED_RANK ? ft_putendl("LEN_B < MED_RANK") : ft_putendl("!is_sort");
			use_b(env);
		}
	}
	while (!is_sort(A, LEN_A, 1))
	{
		ft_putendl("TAMERE");
//		sort_a(env);
	}
	while (LEN_B > 0)
	{
		operate(env, PA);
		send_instruction(env, PA);
	}
}
