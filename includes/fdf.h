/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:39:07 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/27 09:31:17 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
	struct s_vect	*link1;
	struct s_vect	*link2;
}					t_vect;

typedef struct		s_image
{
	void			*image;
	int				bits;
	int				s_l;
	int				endian;
	char			*imgdata;
	int				width;
	int				height;
}					t_image;

typedef struct		s_fdf
{
	char			*mapdir;
	t_list			*maplist;
	char			*line;
	t_vect			cam;
	t_vect			caml;
	t_vect			disppos;
	t_list			*vectlist;
	t_list			*perslist;
	void			*mlx;
	void			*win;
	t_image			*img;
	int				width;
	int				height;
	int				mapw;
	int				maph;
	int				mousex;
	int				mousey;
	int				rotate;
	int				error;
	int				rowlen;
}					t_fdf;

void				ft_readmap(t_fdf *fdf);
void				ft_buildvectlist(t_fdf *fdf);
int					ft_keyread(int keycode, void *param);
void				ft_render(t_fdf *fdf);
void				ft_drawtoimg(t_vect *point, t_image *img);
void				ft_drawtoimgcol(t_vect *point, t_image *img,
					unsigned int col);
void				ft_drawcirc(float cx, float cy, float r, t_fdf *fdf);
void				ft_buildperslist(t_fdf *fdf);
void				ft_updatepers(t_fdf *fdf);
void				ft_drawlinecol(t_vect pointa, t_vect pointb, t_fdf *fdf);
void				ft_buildlinks(t_fdf *fdf);
int					ft_mouse(int x, int y, t_fdf *fdf);
int					ft_renderhook(void *param);
void				ft_drawpoints(t_fdf *fdf);
void				ft_zscale(float scale, t_fdf *fdf);
int					ft_rotate(void *param);

#endif
