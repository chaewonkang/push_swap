/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:27:57 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:27:59 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_wstr_size(const wchar_t *s)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (s[i])
		len += ft_wchar_size(s[i++]);
	return (len);
}
