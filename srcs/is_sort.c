/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:34:01 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/05 16:34:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	not_ranked_dec(t_stack *env, int *st, int len)
{
	int		i;
	int		count;
	int		rank;

	i = -1;
	count = 0;
	rank = -1;
	while(++i + 1 < len)
	{
		if (count == 0 && st[i] < st[i + 1])
		{
			rank = i;
			count++;
			i++;
		}
		if (i + 1 < len && count > 0 &&
				(st[i] < st[i + 1] || (st[i] > st[i - 1] && st[i] != MAX_B)))
			return (-1);
	}
	ft_printf("RANK_TO_ROT = %d\n", rank);
	return (rank);
}

static int	not_ranked_inc(t_stack *env, int *st, int len)
{
	int		i;
	int		count;
	int		rank;

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
				(st[i] > st[i + 1] || (st[i] < st[i - 1] && st[i] != MIN)))
			return (-1);
	}
	ft_printf("RANK_TO_ROT = %d\n", rank);
	return (rank);
}

int			is_not_ranked(t_stack *env, int inc)
{
	int		rank;

	rank = -1;
	if (inc)
		rank = not_ranked_inc(env, A, LEN_A);
	else
		rank = not_ranked_dec(env, B, LEN_B);
	return (rank);
}

int			is_sort(int *st, int len, int start, int inc)
{
	int		i;

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
	ft_putendl("OUI");
	return (1);
}
