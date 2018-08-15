/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:27:57 by tpatter           #+#    #+#             */
/*   Updated: 2018/06/07 16:27:14 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <stdlib.h>

typedef struct	s_fd
{
	char		*str;
	int			line;
	int			totline;
}				t_fd;

int				get_next_line(int fd, char **line);

#endif
