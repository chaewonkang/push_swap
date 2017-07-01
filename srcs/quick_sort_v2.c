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

static void		proceed_op(t_stack *e, int op)
{
	do_op(e, op);
	send_op(e, op);
}

static int		get_dist_to_med(int *st, int size, int next_med)
{
	int			i;

	i = 0;
	while (i < size && st[i] != next_med)
		i++;
	if (i == size)
		return (0);
	return (i);
}

static int		get_next_med(t_stack *e, int *st, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < e->param && e->tab_med[j])
		{
			if (st[i] == e->tab_med[j])
				return (e->tab_med[j]);
			else if (!e->tab_med[j])
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}	

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
				&& (med_pushed = 1))
			proceed_op(e, RA);
		else if (is_med && next_target(st, dist, e->med, 2) == -1)
			med_pushed = 1;
		else if (med_pushed && next_target(st, dist, e->med, 3) == -1)
			proceed_op(e, RRA);
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
		if (next_target(st, dist, e->med, 1) != -1)
			ft_printf("dist = %d\ne->med = %d\nnext target = %d\n", dist, e->med, next_target(st, dist, e->med, 1));
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
				&& (med_pushed = 1))
			proceed_op(e, RB);
		else if (is_med && next_target(st, dist, e->med, 2) == -1)
			med_pushed = 1;
		else if (med_pushed && next_target(st, dist, e->med, 1) == -1)
			proceed_op(e, RRB);
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
			e->med = get_next_med(e, e->stack_a, e->len_a);
			ft_printf("A: next_med_1 = %d\n", e->med);
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
			ft_printf("A: next_med_2 = %d\n", e->med);
			split_a(e, e->stack_a, dist, first_round);
			if (e->stack_a[1] == get_min(e->stack_a, dist))
				proceed_op(e, SA);
		}
		first_round = 1;
		ft_putendl("ON SORT DE A");
		while (is_sort(e->stack_a, e->len_a, 0, 1) && !is_sort(e->stack_b, e->len_b, 0, 0))
		{
			e->med = get_next_med(e, e->stack_b, e->len_b);
			ft_printf("B: next_med_1 = %d\n", e->med);
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
			ft_printf("B: next_med_2 = %d\n", e->med);
			split_b(e, e->stack_b, dist);
			if (e->stack_b[1] == get_max(e->stack_b, e->len_b))
				proceed_op(e, SB);
		}
		ft_putendl("ON SORT DE B");
	}
	while (e->len_b)
		proceed_op(e, PA);
}
