/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:39:07 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/17 22:19:46 by talon            ###   ########.fr       */
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

typedef struct	s_image
{
	void		*image;
	int			bits;
	int			s_l;
	int			endian;
	char		*imgdata;
	int			width;
	int			height;
}				t_image;

typedef struct	s_fdf
{
	char		*mapdir;
	t_list		*maplist;
	char		*line;
	t_vect		cam;
	t_vect		caml;
	t_vect		disppos;
	t_list		*vectlist;
	t_list		*perslist;
	void		*mlx;
	void		*win;
	t_image		*img;
	int			width;
	int			height;
	int			mapw;
	int			maph;
}				t_fdf;

void			ft_readmap(t_fdf *fdf);
void			ft_buildvectlist(t_fdf *fdf);
int				ft_keyread(int keycode, void *param);
void			ft_render(t_fdf *fdf);
void			ft_drawtoimg(t_vect *point, t_image *img);
void			ft_drawcirc(float cx, float cy, float r, t_fdf *fdf);
void			ft_buildperslist(t_fdf *fdf);
void			ft_updatepers(t_fdf *fdf);

#endif
