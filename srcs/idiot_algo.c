/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idiot_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:51:31 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/04 21:33:03 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		shift(t_stack *env, int len, int rank)
{
	if (rank <= MED_RANK)
	{
		while (rank > 0)
		{
			do_op(env, RA);
			send_op(env, RA);
			rank--;
		}
	}
	else
	{
		if (rank + 1 == LEN_A - 1 && A[rank] == MAX && A[LEN_A - 1] < A[0])
			rank++;
		while (rank < len)
		{
			ft_putendl("YES");
			do_op(env, RRA);
			send_op(env, RRA);
			rank++;
		}	
	}
	ROT_FOR_RANK = 2;
}

//GROS BORDEL - RECOMMENCER EN TENANT COMPTE DES DISTANCES (ABS(A[0] - A[1])) ??

static void		sort_a(t_stack *env)
{
	int			op;
	int			rank;

//ATTENTION AUX INDEX - LES VALEURS NE SONT PAS FORCEMENT CONTINUES

	op = 0;
	if (!ROT_FOR_RANK && (rank = is_sort_not_ranked(env, 1)) > -1)
		shift(env, LEN_A, rank);
	else if (A[0] - 1 == A[LEN_A - 1] && A[0] - 2 == A[1] && (op = SA))
	{
		ft_putendl("FIRST SA");
		do_op(env, SA);
	}
	else if (A[0] - 1 == A[LEN_A - 1] && A[0] - A[1] > 1 && (op = RA))
	{
		ft_putendl("FIRST RA");
		do_op(env, RA);
	}
	else if (A[0] < A[1] && A[0] < A[LEN_A - 1] &&
			A[1] - A[0] > A[LEN_A - 1] - A[0] && !is_sort(A, LEN_A - MED_RANK, MED_RANK, 1) && (op = RRA))
	{
		ft_putendl("FIRST RRA");
		do_op(env, RRA);
	}
	else if (A[0] > A[1] && (op = SA))
	{
		ft_putendl("SECOND SA");
		do_op(env, SA);
	}
	else if (A[1] == A[0] + 1 && A[1] == A[LEN_A - 1] - 1 && (op = RRA))
		do_op(env, RRA);
	else if (is_sort(A, LEN_A - MED_RANK, 0, 1) && (op = RRA)) // FAIRE PAREIL SUR 2EME MOIT
		do_op(env, RRA);
//	else if (A[LEN_A - 1] == MAX && (op = RRA))
//		do_op(env, RRA);
	else if (ft_abs(A[1] - A[0]) > ft_abs(A[LEN_A - 1] - A[1]) && (op = RRA))
	{
		ft_putendl("ABS RRA");
		do_op(env, RRA);
	}
	else if ((op = RA))
	{
		ft_putendl("SECOND RA");
		do_op(env, RA);
	}
	if (op)
		send_op(env, op);
	if (ROT_FOR_RANK > 0)
		ROT_FOR_RANK--;
}

void			idiot_push_swap(t_stack *env)
{
	while (!is_sort(A, LEN_A, 0, 1))
		sort_a(env);
	ROT_FOR_RANK = 0;
}


/*  if ( i == len - 1)
 *      i = 0;
 *          else if (count == 0 && i > 0 && st[i] > st[i - 1] && st[i]  > st[i + 1])
 *              {
 *                  count++;
 *                      rank = i;
 *                          }*/
