/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:03:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/28 17:57:58 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		display_stacks(t_stack *e)
{
	int		i;

	i = 0;
	ft_printf("STACK A: \n");
	while (i < LEN_A)
	{
		ft_printf("%d\n", A[i]);
		i++;
	}
	i = 0;
	ft_printf("\nSTACK B: \n");
	while (i < LEN_B)
	{
		ft_printf("%d\n", B[i]);
		i++;
	}
	ft_putchar('\n');
}

void		send_op(t_stack *e, int op)
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
	MOVES++;
}

void			push_swap(t_stack *e)
{
	int			i;

	if (is_sort(e->stack_a, e->len_a, 0, 1))
		return ;
	if (!(e->tab = ft_memalloc(sizeof(int) * e->param)))
		exit(ft_end(4));
	i = 0;
	while (i < e->len_a)
	{
		e->tab[i] = e->stack_a[i];
		i++;
	}
	TAB = bubble_sort(TAB, PARAM);
	if (PARAM < 5)	
		simple_sort(e, MIN, MAX);
	else if (PARAM < 11)
		few_values_sort(e);
	else
		quick_sort(e);
	ft_printf("MOVES = %d\n", MOVES);
}
