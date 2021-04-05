/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_hex_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:14:31 by ckang             #+#    #+#             */
/*   Updated: 2021/04/05 19:14:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_hex_flags_right(int size, t_info *info)
{
	if (WIDTH > 0 && FILL_L >= 0)
		FILL_R = WIDTH - size - FILL_L;
	else
		FILL_R = 0;
	RIGHT_B = FILL_R;
}

static void ft_absolute(t_info *info)
{
	LEFT_B < 0 ? LEFT_B = 0 : LEFT_B;
	LEFT_Z < 0 ? LEFT_Z = 0 : LEFT_Z;
	FILL_L += LEFT_Z + LEFT_B;
}

void ft_hex_flags_left(int size, int precision, t_info *info)
{
	if (MINUS)
	{
		if (SHARP)
			FILL_L += 2;
	}
	else
	{
		if (SHARP)
		{
			FILL_L += 2;
			if (ZERO && WIDTH > size + 2)
				LEFT_Z = WIDTH - size - 2;
			else if (WIDTH > size + 2)
				LEFT_B = WIDTH - precision - size - 2;
		}
		else
		{
			if (ZERO && WIDTH > size)
				LEFT_Z = WIDTH - size;
			else if (WIDTH > size)
				LEFT_B = WIDTH - precision - size;
		}
	}
	ft_absolute(info);
}
