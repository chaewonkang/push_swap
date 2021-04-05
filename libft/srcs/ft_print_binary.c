/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:20:09 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:20:10 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_print_binary(size_t nb)
{
	char *tab;

	tab = "01";
	if (nb < 2)
		ft_putchar(tab[nb]);
	if (nb >= 2)
	{
		ft_print_binary(nb / 2);
		ft_putchar(tab[nb % 2]);
	}
}
