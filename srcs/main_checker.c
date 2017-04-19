/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:08:14 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/18 17:29:58 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_arg(char **arg)
{
	int			i;
	int			j;

	i = 1;
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

	return (1);
}

int				main(int argc, char **argv)
{
	char		**arg;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		arg = ft_strsplit(argv[1], ' ');
	else
		arg = argv;
	if (!check_arg(arg))
		exit(ft_end(1));
	ft_putendl("OK");
	check(arg);
	return (0);
}
