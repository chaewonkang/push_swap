/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:21:05 by ckang             #+#    #+#             */
/*   Updated: 2021/03/13 20:21:05 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_str_to_print(char *s, t_info *info)
{
	size_t len;
	int size;

	len = 0;
	size = (int)ft_strlen(s);
	if (IS_PRECISION)
		PRECISION < size ? (size = PRECISION) : size;
	ft_char_flags_left(size, info);
	ft_char_flags_right(size, info);
	len += ft_char_print_left(info);
	len += size;
	ft_putnstr(s, size);
	len += ft_char_print_right(info);
	return (len);
}

size_t ft_print_str(va_list *arg, t_info *info)
{
	char *s;
	size_t len;

	len = 0;
	s = va_arg(*arg, char *);
	if (!s && !IS_PRECISION)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!s)
		return (0);
	len = ft_str_to_print(s, info);
	return (len);
}
