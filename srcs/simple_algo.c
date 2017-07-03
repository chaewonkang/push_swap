/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:52:53 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/15 15:01:55 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			shift_a(t_stack *e, int len, int rank, int pb)
{
	if (rank < LEN_A / 2)
	{
		while (rank > 0)
		{
			do_op(e, RA);
			send_op(e, RA);
			rank--;
		}
	}
	else
	{
		if (pb)
			rank--;
		while (rank + 1 < len)
		{
			do_op(e, RRA);
			send_op(e, RRA);
			rank++;
		}	
	}
}

static void		sort_a(t_stack *e, int min, int max)
{
	int			op;
	int			rank;

	op = 0;
	if ((rank = is_not_ranked(e, 1)) > 0)
		shift_a(e, LEN_A, rank, 0);
	else if (((A[0] != max && A[0] > A[1]) || (A[0] == min && A[1] == max))
			&& (op = SA))
		do_op(e, SA);
	else if ((op = RA))
		do_op(e, RA);
	if (op)
		send_op(e, op);
}

void			simple_sort(t_stack *e, int min, int max)
{
	while (!is_sort(A, LEN_A, 0, 1))
		sort_a(e, min, max);
}
