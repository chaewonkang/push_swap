/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:22:08 by ckang             #+#    #+#             */
/*   Updated: 2021/07/06 16:20:14 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_end(int status)
{
	if (status == 0 || status == 10)
	{
		if (status == 0)
			ft_putendl("OK");
		return (0);
	}
	if (status == 1)
		ft_putendl_fd("Error", 2);
	else if (status == 2)
	{
		ft_putendl("KO");
		return (0);
	}
	else if (status == 3)
		ft_putendl_fd("Error (read)", 2);
	else if (status == 4)
		ft_putendl_fd("Error (malloc)", 2);
	return (-1);
}
