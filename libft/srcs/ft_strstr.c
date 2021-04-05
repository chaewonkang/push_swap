/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:27:06 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:27:07 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == *little)
		{
			j = 0;
			while (little[j] && little[j] == big[i + j])
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
