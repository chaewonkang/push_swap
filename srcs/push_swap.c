/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:52:48 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/17 21:53:52 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		push_swap(char **arg, int param)
{
	int	tab[12] = {0};
	int	i;

	(void)arg;
	tab[0] = param;
	i = 0;
	while (i < 12)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
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
	push_swap(arg, param);
	return (0);
}
