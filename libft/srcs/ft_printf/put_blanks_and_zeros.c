/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blanks_and_zeros.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:22:32 by ckang             #+#    #+#             */
/*   Updated: 2021/03/13 20:22:33 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_print_blanks(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

void ft_print_zeros(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0');
		i++;
	}
}
