/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_med_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:30:23 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/08 16:27:36 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		get_max_b(t_stack *env)
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

void			get_min_med_max(t_stack *env)
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
	get_max_b(env);
	ft_printf("MED = %d\nMED_RANK = %d\nMAX_B = %d\n", MED, MED_RANK, MAX_B);
}
