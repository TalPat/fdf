/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderhook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:44:47 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/26 15:08:27 by tpatter          ###   ########.fr       */
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
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->image, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img->image);
	fdf->img->image = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	if (fdf->caml.z > 2 * M_PI)
		fdf->caml.z -= 2 * M_PI;
	if (fdf->caml.z < 0)
		fdf->caml.z += 2 * M_PI;
	return (0);
}
