/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:07:35 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/02 20:09:29 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		new_link(t_algo **last, t_algo *new, t_stack *env, int idiot)
{
	if (*last)
		*last->next = new;
	else
	{
		if (idiot)
			IDIOT = new;
		else
			SMART = new;
		*last = new;
	}
}

static int      list_input(t_env *env, char **line, t_room **room)
{
	t_input     *last;

	if (!env->input)
	{
		if (!(env->input = store_input(env, line, room)))
		{
			free(*line);
			return (0);
		}
	}
	else
	{
		if (!(last = store_input(env, line, room)))
		{
			free(*line);
			return (0);
		}
		ft_push_bck(&env->input, last);
	}
	return (1);
}

void		store_op(t_stack *env, int op, int idiot)
{
	t_algo		*algo;
	t_algo		*new;

	algo = (idiot ? LAST_IDIOT : LAST_SMART);
	if (!(new = ft_memalloc(sizeof(t_algo))))
		exit(ft_end(4, NULL));
	new->op = op;
	new_link(&algo, new, env, idiot);
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
