/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_med_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:30:23 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/27 19:34:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				get_max(int *st, int len)
{
	int			i;
	int			j;
	int			max;

	max = INT_MIN;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (st[j] > max)
				max = st[j];
		}
	}
	return (max);
}

int				get_min(int *st, int len)
{
	int			i;
	int			j;
	int			min;

	min = INT_MAX;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (st[j] < min)
				min = st[j];
		}
	}
	return (min);
}

int				get_med(int *st, int len)
{
	int			i;
	int			j;
	int			dist;
	int			med;

	i = -1;
	med = 0;
	while (++i < len)
	{
		dist = 0;
		j = -1;
		while (++j < len)
		{
			if (st[j] > st[i])
				dist++;
		}
		if (dist == (len % 2 == 0 ? (len / 2) - 1 : len / 2))
		{
			med = st[i];
			break ;
		}
	}
	return (med);
}

static void		get_max_b(t_stack *e)
{
	I = -1;
	while (++I < LEN_A)
	{
		DIST = 0;
		J = -1;                                                                                  while (++J < LEN_A)
		{
			if (A[J] > A[I])
				DIST++;
		}
		if (MAX_B == INT_MIN && DIST == (PARAM % 2 == 0 ? MED_RANK : MED_RANK + 1))
			MAX_B = A[I];
		if (DIST == (PARAM % 2 == 0 ? MED_RANK - 1 : MED_RANK))
			MED = A[I];
		if (MAX_B != INT_MIN && MED != INT_MIN)
			break ;
	}
}



void			get_min_med_max(t_stack *e)
{
	MED_RANK = PARAM / 2;
	I = -1;
	while (++I < LEN_A)
	{
		if (A[I] < MIN)
			MIN = A[I];
		if (A[I] > MAX)
			MAX = A[I];
	}
	MAX_B = INT_MIN;
	MED = INT_MIN;
	get_max_b(e);
//	ft_printf("MED = %d\nMED_RANK = %d\nMAX_B = %d\n", MED, MED_RANK, MAX_B);
}
