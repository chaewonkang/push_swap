/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:38:22 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/05 21:10:13 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "time.h"

static void		init_display(t_display *dsp)
{
	dsp->stacks = 0;
	dsp->refresh = 0;
	dsp->colors = 0;
	dsp->algo = 0;
	dsp->is_moves = 0;
	dsp->moves = 0;
	dsp->flags = 0;
}

void			parse_display(char **argv, t_display *dsp)
{
	int			i;

	init_display(dsp);
	i = 1;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-s"))
			dsp->stacks = 1;
		else if (ft_strequ(argv[i], "-r"))
			dsp->refresh = 1;
		else if (ft_strequ(argv[i], "-c"))
			dsp->colors = 1;
		else if (ft_strequ(argv[i], "-a"))
			dsp->algo = 1;
		else if (ft_strequ(argv[i], "-m"))
			dsp->is_moves = 1;	
		i++;
	}
	dsp->flags = dsp->stacks + dsp->refresh + dsp->colors + dsp->algo +
		dsp->is_moves;
}
