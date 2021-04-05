/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:54:05 by ckang             #+#    #+#             */
/*   Updated: 2021/04/05 19:14:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_not_ranked(t_stack *e, int *st, int len)
{
	int i;
	int count;
	int rank;

	i = -1;
	count = 0;
	rank = -1;
	while (++i + 1 < len)
	{
		if (count == 0 && st[i] > st[i + 1])
		{
			rank = i;
			count++;
			i++;
		}
		if (i + 1 < len && count > 0 &&
			(st[i] > st[i + 1] ||
			 (st[i] < st[i - 1] &&
			  (st[i] != e->min || st[i - 1] != e->max))))
			return (-1);
	}
	return (rank);
}

int is_sorted(int *st, int len, int start, int inc)
{
	int i;

	i = start - 1;
	if (inc)
	{
		while (++i + 1 < len)
		{
			if (st[i] >= st[i + 1])
				return (0);
		}
	}
	else
	{
		while (++i + 1 < len)
		{
			if (st[i] <= st[i + 1])
				return (0);
		}
	}
	return (1);
}
