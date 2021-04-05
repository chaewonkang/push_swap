/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:16:17 by ckang             #+#    #+#             */
/*   Updated: 2021/04/05 19:14:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_initialize_struct(t_info *info)
{
	SPEC = 0;
	ft_bzero(FLAGS, 7);
	WIDTH = 0;
	IS_PRECISION = 0;
	PRECISION = 0;
	MOD = NO_MOD;
	LEFT_Z = 0;
	LEFT_B = 0;
	RIGHT_B = 0;
	FILL_L = 0;
	FILL_R = 0;
	HEX_UPPER = 0;
}
