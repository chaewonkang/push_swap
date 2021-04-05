/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:18:12 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:18:13 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;
	t_list *tmp;

	tmp = begin_list;
	i = 0;
	while (tmp->next && i != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
