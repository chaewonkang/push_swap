/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:20:02 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:20:03 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int ft_power(int nb, int power)
{
	long long int r;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	r = nb;
	while (power > 1)
	{
		r = r * nb;
		power--;
	}
	return (r);
}
