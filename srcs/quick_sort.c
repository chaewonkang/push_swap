/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/11 21:16:56 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort_b(t_stack *env)
{
	int			i;

	i = I;
}

static void		push_b(t_stack *env, int div, int div_params)
{
	int			i;
	int			target;
	int			*tab;

	tab = ft_memalloc(sizeof(int) * div_params);
	i = -1;
	while (++i < div_params)
		tab[i] = TAB[div + i];
	i = -1;
	while (++i < div_params)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
	}
	J = -1;
	ft_putendl("COUCOU");
	exit(0);
	while (++J < div_params)
	{
	//	if 
		target = next_target(A, LEN_A, TAB[div - I + J], 2);
		shift_a(env, LEN_A, target, 1);
		do_op(env, PB);
		send_op(env, PB);
		sort_b(env);
	}
	free(tab);
}	

void		quick_sort(t_stack *env)
{
	int		div;
	int		div_params;

	div_params = 2;
	TAB = bubble_sort(A, LEN_A);
	// TROUVER UN MOYEN DE BIEN FORMER LES GROUPES
	div = (PARAM % 2 == 0 ? PARAM / div_params - 1 : PARAM / div_params);
	I = 0;
	while (div - I > 0)
	{
		push_b(env, div, div_params);
		I -= div_params;
	}
	//meme chose dans l'autre sens;
}
