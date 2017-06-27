/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/27 19:36:11 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//GET_MED

static void		proceed_op(t_stack *e, int op)
{
	do_op(e, op);
	send_op(e, op);
}

static void		add_med(int **tab, int size, int val)
{
	int		i;

	i = 0;
	val = 12;
	size = 15;
	*tab[0] = 18;
/*	while (i < size)
	{
		if (tab[i] != 0) 
			i++;
		else
			tab[i] = val;
	}*/
}

void			quick_sort(t_stack *e)
{
	int			i;
	int			op;
	int			is_med;
	int			med_pushed;

	e->tab_med = (int*)ft_memalloc(sizeof(int) * e->param);
//	ft_bzero(e->tab_med, e->param);
	add_med(&e->tab_med, e->param, get_med(e->stack_a, e->len_a));
	i = 0;
	e->med = e->tab[i];
	ft_printf("tab[0] = %d\n", e->tab[i]);
	while (e->len_a > 3)
	{
		is_med = 0;
		med_pushed = 0;
		if (e->len_a < 5 && is_sort(e->stack_a, e->len_a, 0, 1))
			break ;
		if (e->stack_a[0] < e->med || (e->stack_a[0] == e->med &&
					(is_med = 1) && (med_pushed = 1)))
			op = PB;
		else
			op = RA; 
		proceed_op(e, op);
		if (is_med && next_target(e->stack_a, e->len_a, e->med, 1) != -1)
			proceed_op(e, RB);
		else if (!is_med && next_target(e->stack_a, e->len_a, e->med, 1) == -1)
			proceed_op(e, RRB);
	}
}
