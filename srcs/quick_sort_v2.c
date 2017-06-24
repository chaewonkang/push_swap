/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/21 18:33:45 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//GET_MED


void		ft_add_op(t_op **op, t_op *new)
{
	t_op	*tmp;

	if (*op)
	{
		tmp = *op;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*op = new;
}


static void	proceed_op(t_stack *env, int op)
{
	do_op(env, op);
	send_op(env, op);
}

void		quick_sort(t_stack *env)
{


	rank = next_target(A, LEN_A, MED, 2);
	shift_a(env, LEN_A, rank, 1);
	//	proceed_op(env, PB);
	I = MED_RANK + 2;
	J = MED_RANK - 2;
	//	push_b(env);
	//	if (B[0] < B[1])
	//		proceed_op(env, RB);
	//	proceed_op(env, PB);
	//	proceed_op(env, RB);
	//	while (LEN_B > 0)
	//		proceed_op(env, PA);
}
