/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:15:05 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:15:07 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_chrpos(const char *chr, char c)
{
	int i;

	i = 0;
	while (chr[i])
	{
		if (chr[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
