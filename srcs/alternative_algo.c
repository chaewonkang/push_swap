/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:04:53 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/10 15:19:27 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

__unused static void		put_to_a(t_stack *env)
{
	do_op(env, PA);
	send_op(env, PA);
}

static void		put_to_b(t_stack *env)
{
	do_op(env, PB);
	send_op(env, PB);
}

void			alt_push_swap(t_stack *env)
{
	while (LEN_B < PARAM)
	{
		put_to_b(env);
		if (LEN_B > 1 && LEN_A > 1 && B[0] < MED && A[0] > MED)
		{
			do_op(env, RR);
			send_op(env, RR);
		}
		else if (LEN_B > 1 && B[0] < MED)
		{
			do_op(env, RB);
			send_op(env, RB);
		}
	}
/*	while (LEN_A < PARAM)
	{
		put_to_a(env);
		if (LEN_A > 1 && A[0] > A[1])
		{
			do_op(env, RA);
			send_op(env, RA);
		}
	}*/
	push_swap(env);
//	while (!is_sort(A, LEN_A, 0, 1))
//		simple_push_swap(env, MED, MAX);
}
