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

static int		check_stack(t_stack *env, int find_dup)
{
	I = -1;
	if (find_dup)
	{
		while (++I + 1 < PARAM)
		{
			J = -1;
			while (++J < PARAM)
			{
				if (I == J && J < PARAM)
					++J;
				if (A[I] == A[J] && I != J)
					return (0);
			}
		}
	}
	else
	{
		while (++I + 1 < PARAM)
		{
			if (A[I] >= A[I + 1])
				return (0);
		}
	}
	return (1);
}

static void		get_instructions(t_stack *env)
{
	char		*line;
	int		ret;
	int		i;

	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			exit(ft_end(3, NULL));
		OP_OK = 0;
		if (!get_operations(line, env))
			exit(ft_end(1, NULL));
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
		free(line);
	}
}

static void		checker(char **arg, int param)
{
	int		r;
	t_stack		*env;

	if (!(env = ft_memalloc(sizeof(t_stack))))
		exit(ft_end(4, NULL));
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
	if (!check_stack(env, 1))
		exit(ft_end(1, NULL));
	get_instructions(env);
	check_stack(env, 0) && LEN_B == 0 ? exit(ft_end(0, env)) : exit(ft_end(2, NULL));
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
