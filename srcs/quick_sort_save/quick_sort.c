/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/29 17:13:24 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		add_med(int **tab_med, int size, int val)
{
	int		i;
	int		*tab;

	tab = *tab_med;
	i = 0;
	while (i < size)
	{
		if (!tab[i])
		{
			tab[i] = val;
			return ;
		}
		i++;
	}
}

static void		split_b(t_stack *e, int *st, int dist)
{
	int			med_pushed;
	int			is_med;
	int			op;
	int			back_in_order;

	med_pushed = 0;
	back_in_order = 0;
	while (!med_pushed || next_target(st, dist, e->med, 3) != -1)
	{
		is_med = 0;
		if (st[0] > e->med || (st[0] == e->med &&
					(is_med = 1)))
		{
			dist--;
			op = PA;
		}
		else
		{
			back_in_order++;
			op = RB;
		}
		proceed_op(e, op);
		if (is_med && next_target(st, dist, e->med, 3) != -1
				&& (med_pushed = 1) && e->len_a > 1)
			proceed_op(e, RA);
		else if (is_med && next_target(st, dist, e->med, 2) == -1)
			med_pushed = 1;
		else if (med_pushed && next_target(st, dist, e->med, 3) == -1)
			proceed_op(e, RRA);
		if (e->len_b > 1 && e->stack_b[1] == get_max(e->stack_b, e->len_b))
			proceed_op(e, SB);
	}
	while (back_in_order && !is_sort(st, e->len_b, 0, 0))
	{
		proceed_op(e, RRB);
		back_in_order--;
	}
}

static void		split_a(t_stack *e, int *st, int dist, int first_round)
{
	int			med_pushed;
	int			is_med;
	int			op;
	int			back_in_order;

	med_pushed = 0;
	back_in_order = 0;
	while (!med_pushed || next_target(st, dist, e->med, 1) != -1)
	{
		is_med = 0;
		if (st[0] < e->med || (st[0] == e->med &&
					(is_med = 1)))
		{
			dist--;
			op = PB;
		}
		else
		{
			back_in_order++;
			op = RA; 
		}
		proceed_op(e, op);
		if (is_med && next_target(st, dist, e->med, 1) != -1
				&& (med_pushed = 1) && e->len_b > 1)
			proceed_op(e, RB);
		else if (is_med && next_target(st, dist, e->med, 2) == -1)
			med_pushed = 1;
		else if (med_pushed && next_target(st, dist, e->med, 1) == -1)
			proceed_op(e, RRB);
		if (e->len_a > 1 && e->stack_a[1] == get_min(e->stack_a, e->len_a))
			proceed_op(e, SA);
	}
	while (first_round && back_in_order && !is_sort(st, e->len_a, 0, 1))
	{
		proceed_op(e, RRA);
		back_in_order--;
	}
}	

void			quick_sort(t_stack *e)
{
	int			i;
	int			dist;
	int			first_round;

	e->tab_med = (int*)ft_memalloc(sizeof(int) * e->param);
	i = 0;
	first_round = 0;
	while (!is_sort(e->stack_a, e->len_a, 0, 1) || !is_sort(e->stack_b, e->len_b, 0, 0))
	{
		while (!is_sort(e->stack_a, e->len_a, 0, 1))
		{
			if (e->stack_a[1] == get_min(e->stack_a, e->len_a))
				proceed_op(e, SA);
			if (is_sort(e->stack_a, e->len_a, 0, 1))
				break ;
			e->med = get_next_med(e, e->stack_a, e->len_a);
			dist = get_dist_to_med(e->stack_a, e->len_a, e->med);
			if (e->med && dist > 2 && !is_sort(e->stack_a, dist, 0, 1))
			{
				add_med(&e->tab_med, e->param, get_med(e->stack_a, dist));
				e->med = get_next_med(e, e->stack_a, dist);
				i++;
			}
			else if (!e->med)
			{
				add_med(&e->tab_med, e->param, get_med(e->stack_a, e->len_a));
				e->med = e->tab_med[i];
				dist = e->len_a;
				i++;
			}
			split_a(e, e->stack_a, dist, first_round);
			if (e->stack_a[1] == get_min(e->stack_a, e->len_a))
				proceed_op(e, SA);
		}
		first_round = 1;
		while (is_sort(e->stack_a, e->len_a, 0, 1) && !is_sort(e->stack_b, e->len_b, 0, 0))
		{
			if (e->stack_b[1] == get_max(e->stack_b, e->len_b))
				proceed_op(e, SB);
			if (is_sort(e->stack_b, e->len_b, 0, 0))
				break ;
			e->med = get_next_med(e, e->stack_b, e->len_b);
			dist = get_dist_to_med(e->stack_b, e->len_b, e->med);
			if (e->med && dist > 2 && !is_sort(e->stack_b, dist, 0, 2))
			{
				add_med(&e->tab_med, e->param, get_med(e->stack_b, dist));
				e->med = get_next_med(e, e->stack_b, dist);
				i++;
			}
			else if (!e->med)
			{
				add_med(&e->tab_med, e->param, get_med(e->stack_b, e->len_b));
				e->med = e->tab_med[i];
				dist = e->len_b;
				i++;
			}
			split_b(e, e->stack_b, dist);
			if (e->stack_b[1] == get_max(e->stack_b, e->len_b))
				proceed_op(e, SB);
		}
	}
	while (e->len_b)
		proceed_op(e, PA);
}
