/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:39:07 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/16 13:15:57 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

typedef struct	s_vect
{
	float		x;
	float		y;
	float		z;
}				t_vect;

typedef struct	s_fdf
{
	char		*mapdir;
	t_list		*maplist;
	char		*line;
	t_vect		cam;
	t_vect		caml;
	t_vect		disppos;
	t_list		*vectlist;
	void		*mlx;
	void		*win;
}				t_fdf;

void			ft_readmap(t_fdf *fdf);
void			ft_buildvectlist(t_fdf *fdf);
int				ft_keyread(int keycode, void *param);

#endif
