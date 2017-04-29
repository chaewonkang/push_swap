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

static void		print_instruction(int op)
{
	if (op == SA)
		ft_putendl("sa");
	else if (op == SB)
		ft_putendl("sb");
	else if (op == SS)
		ft_putendl("ss");
	else if (op == PA)
		ft_putendl("pa");
	else if (op == PB)
		ft_putendl("pb");
	else if (op == RA)
		ft_putendl("ra");
	else if (op == RB)
		ft_putendl("rb");
	else if (op == RR)
		ft_putendl("rr");
	else if (op == RRA)
		ft_putendl("rra");
	else if (op == RRB)
		ft_putendl("rrb");
	else if (op == RRR)
		ft_putendl("rrr");
}

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

	
	if (LEN_B > 1 && B[0] < B[1] && B[0] < B[LEN_B - 1] &&  B[0] - B[1] > B[0] - B[LEN_B - 1] &&  
	if (LEN_B > 1 && !index && A[1] < A[0] && (op = PB))
		operate(env, PB);
	else if (LEN_B > 1 && A[1] < MED && (op == SA))
		operate(env, SA);
	index = next_target(A, LEN_A, MED);
	if (index <= MED_RANK)
	{
	}
	else if (index > MED_RANK)
	{
	}
	print_instrucion(op);
}

void			push_swap(t_stack *env)
{
	int			op;

	while (LEN_B < MED_RANK || !is_sort(B, 0))
		put_to_b(env);
	while (LEN_A < PARAM || !is_sort(A, 1))
	{
//		while (
		if (LEN_A > 1 && LEN_B > 1 && A[0] > A[1] && B[0] > B[1] && (op = SS))
			operate(env, SS);
		else if (LEN_A > 1 && A[0] > A[1] && (op = SA))
			operate(env, SA);
		print_instruction(op);
	}
}
