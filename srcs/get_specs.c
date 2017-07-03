/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:02:04 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/11 17:44:15 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		find_dup(t_stack *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i + 1 < e->param)
	{
		j = -1;
		while (++j < e->param)
		{
			if (i == j && j < e->param)
				++j;
			if (e->stack_a[i] == e->stack_a[j] && i != j)
				return (1);
		}
	}
	return (0);
}

static void		get_specs(char **arg, int param, int dsp)
{
	int			i;
	t_stack		e;

	e.param = param;
	if (!(e.stack_a = ft_memalloc(sizeof(int) * e.param)) ||
			!(e.stack_b = ft_memalloc(sizeof(int) * e.param)))
		exit(ft_end(4));
	e.len_a = e.param;
	e.len_b = 0;
	e.display_stacks = dsp;
	i = -1;
	while (arg[++i])
	{
		e.stack_a[i] = ft_atoi(arg[i]);
		free(arg[i]);
	}
	free(arg);
	if (find_dup(&e))
		exit(ft_end(1));
	push_swap(&e);
	exit(ft_end(10));
}

static int		get_format(char **arg)
{
	int			i;
	int			j;

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

int				main(int argc, char **argv)
{
	char		**arg;
	int			i;
	int			param;
	int			dsp;

	if (argc < 2)
		return (-1);
	dsp = 0;
	if (ft_strequ(argv[1], "-v"))
		dsp = 1;
	if (argc == 2 + dsp)
		arg = ft_strsplit(argv[1 + dsp], ' ');
	else
	{
		if (!(arg = (char**)malloc(sizeof(char*) * (argc - dsp))))
			exit(ft_end(4));
		i = -1;
		while (++i + 1 + dsp < argc)
			arg[i] = ft_strdup(argv[i + 1 + dsp]);
		arg[i] = NULL;
	}
	if (!(param = get_format(arg)))
		exit(ft_end(1));
	get_specs(arg, param, dsp);
	return (0);
}
