/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:19:19 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/03 17:08:45 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		find_dup(t_stack *env)
{
	I = -1;
	while (++I + 1 < PARAM)
	{
		J = -1;
		while (++J < PARAM)
		{
			if (I == J && J < PARAM)
				++J;
			if (A[I] == A[J] && I != J)
				return (1);
		}
	}
	return (0);
}

static void		get_instructions(t_stack *env)
{
	char		*line;
	int			ret;
	int			i;

	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			exit(ft_end(3, NULL));
		OP_OK = 0;
		if (!get_operations(line, env))
			exit(ft_end(1, NULL));
		i = 0;
/*		ft_printf("STACK A: \n");
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
		ft_putchar('\n');*/
		free(line);
	}
}

static void		checker(char **arg, int param)
{
	int			i;
	t_stack		*env;

	if (!(env = ft_memalloc(sizeof(t_stack))))
		exit(ft_end(4, NULL));
	PARAM = param;
	if (!(A = ft_memalloc(sizeof(int) * PARAM)) ||
			!(B = ft_memalloc(sizeof(int) * PARAM)))
		exit(ft_end(4, NULL));
	LEN_A = PARAM;
	i = -1;
	while (arg[++i])
	{
		A[i] = ft_atoi(arg[i]);
		free(arg[i]);
	}
	free(arg);
	if (find_dup(env))
		exit(ft_end(1, NULL));
	get_instructions(env);
	is_sort(A, LEN_A, 1) && LEN_B == 0 ? exit(ft_end(0, env)) : exit(ft_end(2, NULL));
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

	if (argc < 2)
		return (-1);
	if (argc == 2)
		arg = ft_strsplit(argv[1], ' ');
	else
	{
		if (!(arg = (char**)malloc(sizeof(char*) * (argc))))
			exit(ft_end(4, NULL));
		i = -1;
		while (++i + 1 < argc)
			arg[i] = ft_strdup(argv[i + 1]);
		arg[i] = NULL;
	}
	if (!(param = get_format(arg)))
		exit(ft_end(1, NULL));
	checker(arg, param);
	return (0);
}
