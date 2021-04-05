/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:29 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:24:31 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdupchr(const char *s1, char c)
{
	size_t i;
	char *ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlenchr(s1, c) + 1));
	if (!ret)
		return (NULL);
	while (s1[i] && s1[i] != c)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
