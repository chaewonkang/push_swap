/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:03:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/08 21:02:18 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		display_stacks(t_stack *env)
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

void		send_op(t_stack *env, int op)
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
//	if (DISPLAY)
	display_stacks(env);
	MOVES++;
}

/*
static void		read_op(t_stack *env, int idiot)
{
	t_algo		*tmp;

	tmp = (idiot ? IDIOT : SMART);
	while (tmp)
	{
		send_op(env, tmp->op);
		tmp = tmp->next;
	}
}*/

void			push_swap(t_stack *env)
{
	if (is_sort(A, LEN_A, 0, 1))
		return ;
//	idiot_push_swap(env, MIN, MAX);
	smart_push_swap(env);
	if (PARAM > 3)
	{
		ft_printf("MOVES = %d\n", MOVES);
//		if (IDIOT_MOVES < SMART_MOVES)
//			read_op(env, 1);
	}
//	else
//		read_op(env, 0);

}
