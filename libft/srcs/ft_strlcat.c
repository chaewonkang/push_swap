/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:25:18 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:25:19 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	char *cpy_dst;
	const char *cpy_src;
	size_t i;
	size_t len;

	i = size;
	cpy_dst = dst;
	cpy_src = src;
	while (i-- && *cpy_dst)
		cpy_dst++;
	len = cpy_dst - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen((char *)cpy_src));
	while (*cpy_src)
	{
		if (i != 1)
		{
			*cpy_dst++ = *cpy_src;
			--i;
		}
		cpy_src++;
	}
	*cpy_dst = '\0';
	return (len + (cpy_src - src));
}
