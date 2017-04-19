/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:54:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/04/18 19:05:56 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct	s_stack
{
	char	*stack_a;
	char	*stack_b;
}				t_stack;

void		check(char **arg);
int			ft_end(int status);

#endif
