/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:21:02 by ckang             #+#    #+#             */
/*   Updated: 2021/02/24 16:21:03 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
	ft_putchar_fd('\n', fd);
}
