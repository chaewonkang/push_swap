/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:52:53 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/05 12:39:41 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		shift_a(t_stack *e, int len, int rank, int pb)
{
	if (rank < e->len_a / 2)
	{
		while (rank > 0)
		{
			proceed_op(e, RA);
			rank--;
		}
	}
	else
	{
		if (pb)
			rank--;
		while (rank + 1 < len)
		{
			proceed_op(e, RA);
			rank++;
		}	
	}
}

static void		sort_a(t_stack *e)
{
	int			op;
	int			rank;

	op = 0;
	if ((rank = is_not_ranked(e, e->stack_a, e->len_a)) > 0)
		shift_a(e, e->len_a, rank, 0);
	else if (((e->stack_a[0] != e->max && e->stack_a[0] > e->stack_a[1])
		|| (e->stack_a[0] == e->min && e->stack_a[1] == e->max))
			&& (op = SA))
		do_op(e, SA);
	else if ((op = RA))
		do_op(e, RA);
	if (op)
		send_op(e, op);
}

void			simple_sort(t_stack *e)
{
	e->min = get_min(e->stack_a, e->len_a);
	e->max = get_max(e->stack_a, e->len_a);
	while (!is_sorted(e->stack_a, e->len_a, 0, 1))
		sort_a(e);
}
