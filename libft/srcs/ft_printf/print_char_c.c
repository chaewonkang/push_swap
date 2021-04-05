/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:17:26 by ckang             #+#    #+#             */
/*   Updated: 2021/04/05 19:14:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_char_to_print(char c, int size, t_info *info)
{
	size_t len;
	int add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_char_flags_left(size, info);
	ft_char_flags_right(size, info);
	RIGHT_B -= add_precision;
	len += ft_char_print_left(info);
	len += add_precision;
	ft_putchar(c);
	len += ft_char_print_right(info);
	return (len);
}

size_t ft_print_char(va_list *arg, t_info *info)
{
	int c;
	size_t len;

	len = 1;
	c = va_arg(*arg, int);
	len += ft_char_to_print(c, 1, info);
	return (len);
}
