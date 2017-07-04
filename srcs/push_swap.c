/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:03:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/04 18:57:15 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		display_stacks(t_stack *e)
{
	int		i;

	i = 0;
	ft_printf("STACK A: \n");
	while (i < e->len_a)
	{
		ft_printf("%d\n", e->stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nSTACK B: \n");
	while (i < e->len_b)
	{
		ft_printf("%d\n", e->stack_b[i]);
		i++;
	}
	ft_putchar('\n');
}

void		send_op(t_stack *e, char op)
{
	if (op == SA)
		ft_putendl("sa");
	else if (op == SB)
		ft_putendl("sb");
	else if (op == SS)
		ft_putendl("ss");
	else if (op == PA)
		ft_putendl("pa");
	else if (op == PB)
		ft_putendl("pb");
	else if (op == RA)
		ft_putendl("ra");
	else if (op == RB)
		ft_putendl("rb");
	else if (op == RR)
		ft_putendl("rr");
	else if (op == RRA)
		ft_putendl("rra");
	else if (op == RRB)
		ft_putendl("rrb");
	else if (op == RRR)
		ft_putendl("rrr");
	if (e->display_stacks)
		display_stacks(e);
	e->moves++;
}

void			proceed_op(t_stack *e, char op, int store)
{
	if (store)
		store_op(e, op);
	else
	{
		do_op(e, op);
		send_op(e, op);
	}
}

void			push_swap(t_stack *e)
{
	if (is_sorted(e->stack_a, e->len_a, 0, 1))
		return ;
	e->moves = 0;
	if (e->param < 5)	
		simple_sort(e);
	else
		quick_sort(e);
//	if (e->display_stacks)
		ft_printf("MOVES = %d\n", e->moves);
}
