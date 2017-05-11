/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:52:53 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/11 18:13:07 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			shift_a(t_stack *env, int len, int rank, int pb)
{
	ft_putendl("SHIFT_A");
	ft_printf("RANK = %d\n", rank);
	if (rank < LEN_A / 2)
	{
		while (rank > 0)
		{
			do_op(env, RA);
			send_op(env, RA);
			rank--;
		}
	}
	else
	{
		if (pb)
			rank--;
		while (rank + 1 < len)
		{
			do_op(env, RRA);
			send_op(env, RRA);
			rank++;
		}	
	}
}

static void		sort_a(t_stack *env, int min, int max)
{
	int			op;
	int			rank;

	op = 0;
	if ((rank = is_not_ranked(env, 1)) > 0)
		shift_a(env, LEN_A, rank, 0);
	else if (((A[0] != max && A[0] > A[1]) || (A[0] == min && A[1] == max))
			&& (op = SA))
		do_op(env, SA);
	else if ((op = RA))
		do_op(env, RA);
	if (op)
		send_op(env, op);
}

void			simple_sort(t_stack *env, int min, int max)
{
	while (!is_sort(A, LEN_A, 0, 1))
		sort_a(env, min, max);
}
