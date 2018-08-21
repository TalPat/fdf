/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderhook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:44:47 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/21 17:46:34 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

int		ft_renderhook(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	ft_rotate(fdf);
	ft_updatepers(fdf);
	ft_drawpoints(fdf);
	//ft_connectpoints(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->image, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img->image);
	fdf->img->image = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	/**/mlx_string_put(fdf->mlx, fdf->win, 0, 0, 0xffffff, ft_itoa(fdf->caml.x * 1000));
	/**/mlx_string_put(fdf->mlx, fdf->win, 0, 15, 0xffffff, ft_itoa(fdf->caml.y * 1000));
	/**/mlx_string_put(fdf->mlx, fdf->win, 0, 30, 0xffffff, ft_itoa(fdf->caml.z * 1000));
	/**/mlx_string_put(fdf->mlx, fdf->win, 0, 45, 0xffffff, ft_itoa(fdf->cam.x));
	/**/mlx_string_put(fdf->mlx, fdf->win, 0, 60, 0xffffff, ft_itoa(fdf->cam.y));
	/**/mlx_string_put(fdf->mlx, fdf->win, 0, 75, 0xffffff, ft_itoa(fdf->cam.z));
	if (fdf->caml.z > 2 * M_PI)
		fdf->caml.z -= 2 * M_PI;
	if (fdf->caml.z < 0)
		fdf->caml.z += 2 * M_PI;
	return (0);
}