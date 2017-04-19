/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:27:00 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:27:01 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_chr(char const *s, char c, size_t pos)
{
	size_t		len;

	len = 0;
	while (s[len] && s[pos] != c)
	{
		pos++;
		len++;
	}
	return (len);
}

static size_t	copy_and_return_pos(char *ret, char const *s, size_t size_w,
		size_t pos)
{
	size_t		i;

	i = 0;
	while (i < size_w)
	{
		ret[i] = s[pos];
		i++;
		pos++;
	}
	ret[i] = '\0';
	return (pos);
}

static size_t	check_pos(char const *s, size_t pos, char c)
{
	while (s[pos] == c)
		pos++;
	return (pos);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		pos;
	size_t		w;
	size_t		size_ret;
	size_t		size_w;
	char		**ret;

	if (!s)
		return (NULL);
	size_ret = ft_count_w(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (size_ret + 1))))
		return (NULL);
	pos = 0;
	pos = check_pos(s, pos, c);
	w = 0;
	while (w < size_ret)
	{
		size_w = ft_count_chr(s, c, pos);
		if (!(ret[w] = (char*)malloc(sizeof(char) * (size_w + 1))))
			return (NULL);
		pos = copy_and_return_pos(ret[w], s, size_w, pos);
		pos = check_pos(s, pos, c);
		w++;
	}
	ret[w] = 0;
	return (ret);
}
