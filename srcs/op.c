/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:00:13 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/29 17:24:20 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void     reverse_rotate(int *st, int len)
{
	int         i;
	int         j;

	if (len > 1)
	{
		i = st[len - 1];
		j = len;
		while (--j > 0)
			st[j] = st[j - 1];
		st[j] = i;
	}
}

static void     rotate(int *st, int len)
{
	int         i;
	int         j;

	if (len > 1)
	{
		i = st[0];
		j = -1;
		while (++j + 1 < len)
			st[j] = st[j + 1];
		st[j] = i;
	}
}

static void     push(int *st1, int *st2, int *len1, int *len2)
{
	int         i;
	int         j;

	if (*len2 > 0)
	{
		i = st2[0];
		j = -1;
		while (++j + 1 < *len2)
			st2[j] = st2[j + 1];
		*len2 -= 1;
		j = *len1 + 1;
		while (--j > 0)
			st1[j] = st1[j - 1];
		st1[0] = i;
		*len1 += 1;
	}
}

static void     swap(int *tab, int len)
{
	int         i;

	if (len > 1)
	{
		i = tab[0];
		tab[0] = tab[1];
		tab[1] = i;
	}
}


void		operate(t_stack *env, int op)
{
	if (op == SA || op == SS)
		swap(A, LEN_A);
	if (op ==SB || op == SS)
		swap(B, LEN_B);
	else if (op == PA)
		push(A, B, &LEN_A, &LEN_B);
	else if (op == PB)
		push(B, A, &LEN_B, &LEN_A);
	else if (op == RA || op == RR)
		rotate(A, LEN_A);
	if (op == RB || op == RR)
		rotate(B, LEN_B);
	else if (op == RRA || op == RRR)
		reverse_rotate(A, LEN_A);
	if (op == RRB || op == RRR)
		reverse_rotate(B, LEN_B);	
}
