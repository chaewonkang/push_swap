/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:03:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/05 21:10:30 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		send_op(t_stack *e, char op, char algo)
{
//	nanosleep(&(struct timespec){0, 100000000}, 0);
//	ft_putstr("\e[1;1H\e[2J");
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
	if (e->bonus.stacks)
		display_stacks(e);
	if (algo)
		e->bonus.moves++;
}

void			proceed_op(t_stack *e, char op)
{
	t_op		*tmp;

	if (op)
	{
		do_op(e, op);
		store_op(e, op);
	}
	else
	{
		e->moves = 0;
		delete_ops(e->op);
		replace_ops(e->op);
		tmp = *e->op;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			send_op(e, tmp->op, 0);
			tmp = tmp->next;
			e->bonus.moves++;
		}
	}
}

void			push_swap(t_stack *e)
{
	int		algo;

	algo = 0;
	if (is_sorted(e->stack_a, e->len_a, 0, 1))
		return ;
	e->moves = 0;
	if (e->param < 5 && (algo = 1))	
		simple_sort(e);
	else
	{
		quick_sort(e);
		proceed_op(e, NOPE);
		algo = 2;
	}
	if (e->bonus.is_moves || e->bonus.algo)
		ft_putchar('\n');
	if (e->bonus.is_moves)
		ft_printf("Stack A was sorted in %d moves\n",
		e->bonus.moves);
	if (e->bonus.algo)
		algo == 1 ? ft_putendl("Algorithm used: simple sort") :
		ft_putendl("Algorithm used: quick sort");
}
