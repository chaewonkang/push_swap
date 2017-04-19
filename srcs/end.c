/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:22:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/18 19:09:25 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_end(int status)
{
	if (status == 1)
		ft_putendl_fd("ERROR", 2);
	else if (status == 2)
	{
		ft_putendl("KO");
		retur (0);
	}
	else if (status == 3)
		ft_putendl_fd("READ ERROR", 2);
	else if (status == 4)
		ft_putendl_fd("MALLOC ERROR", 2);
	return (-1);
}
