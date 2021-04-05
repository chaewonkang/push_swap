/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:15:15 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:15:17 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_count_w(char const *s, char c)
{
	size_t i;
	size_t n;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
			i++;
		else if (s[i] == c)
		{
			n++;
			while (s[i] == c)
				i++;
		}
	}
	if (s[i] == '\0' && s[i - 1] != c)
		n++;
	return (n);
}
