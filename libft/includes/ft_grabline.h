/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grabline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:14:09 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/05 13:43:50 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRABLINE_H
# define FT_GRABLINE_H

# define BUFF_SIZE 1

typedef struct	s_gnl
{
	char		buff[BUFF_SIZE + 1];
	char		**lines;
	int			myline;
	int			totline;
	char		*line;
}				t_gnl;

int				ft_grabline(int fd, char **line);

#endif
