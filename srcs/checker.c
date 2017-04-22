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

static int		check_stack(t_stack *stack, int find_dup)
{
	I = -1;
	if (find_dup)
	{
		while (++I + 1 < LEN)
		{
			J = -1;
			while (++J < LEN)
			{
				if (I == J && J < LEN)
					++J;
				if (A[I] == A[J] && I != J)
					return (0);
			}
		}
	}
	else
	{
		while (++I + 1 < LEN)
		{
			if (A[I] >= A[I + 1])
				return (0);
		}
	}
	return (1);
}

static void		checker(char **arg, int param)
{
	char		*line;
	int		r;
	t_stack		*stack;

	if (!(stack = ft_memalloc(sizeof(t_stack))))
		exit(ft_end(4));
	PARAM = param;
	A = ft_memalloc(sizeof(int) * PARAM);
	LEN_A = PARAM;
	B = ft_memalloc(sizeof(int) * PARAM);
	r = -1;
	while (arg[++r])
	{
		A[r] = ft_atoi(arg[r]);
		free(arg[r]);
	}
	free(arg);
	if (!check_stack(stack, 1))
		exit(ft_end(1));
	while ((r = get_next_line(0, &line)))
	{
		if (r == -1)
			exit(ft_end(3));
		if (!get_instructions(line, stack))
			exit(ft_end(1));
		free(line);
	}
	check_stack(stack, 0) && !B ? ft_putendl("OK") : exit(ft_end(2));
}

static int		get_format(char **arg)
{
	int		i;
	int		j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		if (ft_strlen(arg[i]) > 11 || ft_atoss(arg[i]) > INT_MAX
				|| ft_atoss(arg[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	char		**arg;
	int		i;
	int		param;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		arg = ft_strsplit(argv[1], ' ');
	else
	{
		if (!(arg = (char**)malloc(sizeof(char*) * (argc))))
			exit(ft_end(4));
		i = -1;
		while (++i + 1 < argc)
			arg[i] = ft_strdup(argv[i + 1]);
		arg[i] = NULL;
	}
	if (!(param = get_format(arg)))
		exit(ft_end(1));
	checker(arg, param);
	return (0);
}
