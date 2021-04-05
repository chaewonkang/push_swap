/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:20:35 by ckang             #+#    #+#             */
/*   Updated: 2021/03/13 20:20:36 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_print_width(t_info *info)
{
	size_t len;

	len = 0;
	ft_print_blanks(WIDTH - 1);
	ft_putchar('%');
	len += WIDTH;
	return (len);
}

size_t ft_print_percent(t_info *info)
{
	size_t len;

	len = 0;
	if (MINUS)
	{
		ft_putchar('%');
		ft_print_blanks(WIDTH - 1);
		len += WIDTH;
	}
	else if (ZERO)
	{
		ft_print_zeros(WIDTH - 1);
		ft_putchar('%');
		len += WIDTH;
	}
	else if (WIDTH)
		len += ft_print_width(info);
	else
	{
		ft_putchar('%');
		len++;
	}
	return (len);
}
