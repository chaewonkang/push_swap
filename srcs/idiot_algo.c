/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idiot_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:51:31 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/03 19:48:07 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort_a(t_stack *env)
{
	int			op;

// VOIR IS_SORT_NOT_RANKED QUAND C EST SORT MAIS PAS RANGE
	op = 0;
	if (is_sort(A, LEN_A - 1, 1) && (op = RRA))
		do_op(env, RRA);
	else if (A[0] < A[1] && A[0] < A[LEN_A - 1] &&
			A[1] - A[0] > A[LEN_A - 1] - A[0] && (op = RRA))
		do_op(env, RRA);
	else if (A[0] > A[1] && (op = SA))
		do_op(env, SA);
	else if ((op = RA))
		do_op(env, RA);
	if (op)
		send_op(env, op);
}

void			idiot_push_swap(t_stack *env)
{
	while (!is_sort(A, LEN_A, 1))
		sort_a(env);
}
