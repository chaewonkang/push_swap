/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:19:19 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/18 19:12:41 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		instruction(char *line)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "ss"))
		swap_a(env);
	else if (ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		swap_b(env);
	else if (ft_strequ(line, "pa"))
		push_a(env);
	else if (ft_strequ(line, "pb"))
		push_b(env);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rr"))
		rotate_a(env);
	else if (ft_strequ(line, "rb") || ft_strequ(line, "rr"))
		rotate_b(env);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrr"))
		reverse_rotate_a(env);
	else if (ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
		reverse_rotate_b(env);
	else
		return (0);
	return (1);
}

void			check(char **arg)
{
	char		*line;
	int			ret;
	t_stack		*stack;

	if (!(stack = ft_memalloc(sizeof(t_stack))))
		exit(ft_end(4));
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			exit(ft_end(3));
		if (!instruction(line, stack))
			exit(ft_end(1));
		free(line);
	}
	if (stack_checked())
		ft_putendl("OK");
	else
		exit(ft_end(2));
}
