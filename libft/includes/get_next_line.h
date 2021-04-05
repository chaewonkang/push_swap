/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:14:02 by ckang             #+#    #+#             */
/*   Updated: 2021/04/05 19:14:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 4096

typedef struct s_line
{
	char *tab;
	int fd;
	struct s_line *next;
} t_line;

int get_next_line(const int fd, char **line);

#endif
