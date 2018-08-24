/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:52:50 by talon             #+#    #+#             */
/*   Updated: 2018/08/24 14:23:12 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

void	ft_drawpoints(t_fdf *fdf)
{
	t_list	*tmp;

	tmp = fdf->perslist;
	fdf->img->imgdata = mlx_get_data_addr(fdf->img->image, &(fdf->img->bits),
								&(fdf->img->s_l), &(fdf->img->endian));
	while (tmp)
	{
		ft_drawtoimg(tmp->content, fdf->img);
		if (((t_vect*)(tmp->content))->link1)
			ft_drawlinecol(*((t_vect*)tmp->content),
							*((t_vect*)(tmp->content))->link1, fdf);
		if (((t_vect*)(tmp->content))->link2)
			ft_drawlinecol(*((t_vect*)tmp->content),
							*((t_vect*)(tmp->content))->link2, fdf);
		tmp = tmp->next;
	}
}

void	ft_render(t_fdf *fdf)
{
	ft_updatepers(fdf);
	ft_drawpoints(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->image, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img->image);
	fdf->img->image = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, 0xffffff,
					ft_itoa(fdf->caml.x * 1000));
	mlx_string_put(fdf->mlx, fdf->win, 0, 15, 0xffffff,
					ft_itoa(fdf->caml.y * 1000));
	mlx_string_put(fdf->mlx, fdf->win, 0, 30, 0xffffff,
					ft_itoa(fdf->caml.z * 1000));
}
