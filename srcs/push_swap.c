/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:03:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/16 20:14:09 by ljoly            ###   ########.fr       */
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


/*
//CHECKER LE DEGRE DE DIFF
static int      ft_comp(t_stack *env)
{
	    MIN = get_min(A, LEN_A);

}*/

void			push_swap(t_stack *env)
{
	int			i;

	//CHECKER LE DEGRE DE DIF >> SI PEU DE DIFF GO FEW_VALUES_ALGO;
	if (is_sort(A, LEN_A, 0, 1))
		return ;
	TAB = ft_memalloc(sizeof(int) * PARAM);
	i = 0;
	while (i < LEN_A)
	{
		TAB[i] = A[i];
		i++;
	}
	TAB = bubble_sort(TAB, PARAM);
//CHECKER SI SORT_NOT_RANKED ET BALANCER DANS FEW VALUES;
//	if (PARAM < 6)	
//	simple_sort(env, MIN, MAX);
//	else if (PARAM < 11)
//	few_values_sort(env);
//	else
	quick_sort(env);
	ft_printf("MOVES = %d\n", MOVES);
}
