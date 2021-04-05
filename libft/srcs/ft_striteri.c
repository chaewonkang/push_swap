/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:53 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:24:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;

	if (!s || !f)
		return;
	i = 0;
	if (s == NULL)
		return;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}
