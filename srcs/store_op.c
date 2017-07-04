/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 18:38:06 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/04 19:34:02 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		new_link(t_op **op, t_op *new)
{
	new->next = *op;
	*op->prev = new;
	*op = new;
}

void			store_op(t_stack *e, char op)
{
	t_op		*new;

	if (!e->op)
	{
		if (!(e->op = (t_op**)ft_memalloc(sizeof(t_op*))))
			exit(ft_end(4));
	}
	if (!(new = ft_memalloc(sizeof(t_op))))
		exit(ft_end(4));
	new->op = op;
	new_link(e->op, new);
}
