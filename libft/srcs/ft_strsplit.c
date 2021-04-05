/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:41:35 by ckang             #+#    #+#             */
/*   Updated: 2021/07/04 14:46:32 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_start_w(char const *s, size_t index, char c)
{
	if (index == 0 && s[index] != c)
		return (1);
	if (s[index] != c && s[index - 1] == c)
		return (1);
	return (0);
}

char **ft_strsplit(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t k;
	char **ret;

	i = 0;
	k = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_count_w(s, c) + 1)))
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		if (is_start_w(s, i, c))
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			ret[k] = ft_strsub(s, i, j);
			k++;
		}
		i++;
	}
	ret[k] = 0;
	return (ret);
}
