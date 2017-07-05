/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_doubles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:15:51 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/05 20:31:02 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		delete(t_op *tmp, t_op *tmp2)
{
	if (tmp2->prev && tmp->next)
	{
		tmp2->prev->next = tmp->next;
		tmp->next->prev = tmp2->prev;
		free(tmp);
	}
	else if (tmp2->prev)
	{
		tmp2->prev->next = NULL;
		free(tmp);
	}
	else if (tmp->next)
	{
		tmp->next->prev = NULL;
		free(tmp);
	}
}

static void		replace(t_op *tmp, t_op *tmp2, char op)
{
	tmp2->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp2;
	tmp2->op = op;
	free(tmp);
}

void			replace_ops(t_op **op)
{
	t_op		*tmp;
	t_op		*tmp2;
	int			rep;

	rep = 0;
	if (*op)
	{
		tmp = *op;
		while (tmp && tmp->next)
		{
			tmp2 = tmp->next;
			if (((tmp->op == RA && tmp2->op == RB) ||
					(tmp->op == RB && tmp2->op == RA)) && (rep = 1))
				replace(tmp, tmp2, RR);
			else if (((tmp->op == RRA && tmp2->op == RRB) ||
					(tmp->op == RRB && tmp2->op == RRA)) && (rep = 1))
				replace(tmp, tmp2, RRR);
			else if (((tmp->op == SA && tmp2->op == SB) ||
					(tmp->op == SB && tmp2->op == SA)) && (rep = 1))
				replace(tmp, tmp2, SS);
			if (rep)
			{
				tmp = *op;
				rep = 0;
			}
			else
				tmp = tmp2;
		}
	}
}

void			delete_ops(t_op **op)
{
	t_op		*tmp;
	t_op		*tmp2;
	int			del;

	del = 0;
	if (*op)
	{
		tmp = *op;
		while (tmp && tmp->prev)
		{
			tmp2 = tmp->prev;
			if (((tmp->op == PA && tmp2->op == PB) ||
						(tmp->op == PB && tmp2->op == PA)) && (del = 1))
				delete(tmp, tmp2);
			else if (((tmp->op == RA && tmp2->op == RRA) ||
						(tmp->op == RRA && tmp2->op == RA)) && (del = 1))
				delete(tmp, tmp2);
			else if (((tmp->op == RB && tmp2->op == RRB) ||
						(tmp->op == RRB && tmp2->op == RB)) && (del = 1))
				delete(tmp, tmp2);
			if (del)
			{
				tmp = *op;
				free(tmp2);
				del = 0;
			}
			else
				tmp = tmp2;
		}
		*op = tmp;
	}
}
