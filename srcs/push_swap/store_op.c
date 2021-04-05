/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:38:06 by ckang             #+#    #+#             */
/*   Updated: 2021/07/06 17:23:08 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void new_link(t_op **op, t_op *new)
{
	new->prev = *op;
	(*op)->next = new;
	*op = new;
}

void store_op(t_stack *e, char op)
{
	t_op *new;

	if (!(new = (t_op *)ft_memalloc(sizeof(t_op))))
		exit(ft_end(4));
	new->op = op;
	new->i = e->moves;
	if (*e->op)
		new_link(e->op, new);
	else
		*e->op = new;
}
