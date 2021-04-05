/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:20:24 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:20:25 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_print_octal(size_t nb)
{
	char *tab;

	tab = "01234567";
	if (nb < 8)
		ft_putchar(tab[nb]);
	if (nb >= 8)
	{
		ft_print_octal(nb / 8);
		ft_putchar(tab[nb % 8]);
	}
}
