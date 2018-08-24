/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:02:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/24 14:23:21 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

void			ft_keycom3(int keycode, t_fdf *fdf)
{
	if (keycode == 7)
		fdf->cam.z += 0.5;
	if (keycode == 6)
		fdf->cam.z -= 0.5;
	if (keycode == 27)
		fdf->disppos.z += 100;
	if (keycode == 24)
		fdf->disppos.z -= 100;
	if (keycode == 78)
		ft_zscale(0.8, fdf);
	if (keycode == 69)
		ft_zscale(1.2, fdf);
	if (keycode == 15)
	{
		if (fdf->rotate)
			fdf->rotate = 0;
		else
			fdf->rotate = 1;
	}
}

void			ft_keycom2(int keycode, t_fdf *fdf)
{
	if (keycode == 13)
	{
		fdf->cam.x -= 0.5 * sinf(fdf->caml.z) * sinf(fdf->caml.x);
		fdf->cam.y += 0.5 * cosf(fdf->caml.z) * sinf(fdf->caml.x);
		fdf->cam.z -= 0.5 * cosf(fdf->caml.x);
	}
	if (keycode == 0)
	{
		fdf->cam.x += 0.5 * cosf(fdf->caml.z);
		fdf->cam.y += 0.5 * sinf(fdf->caml.z);
	}
	if (keycode == 1)
	{
		fdf->cam.x += 0.5 * sinf(fdf->caml.z) * sinf(fdf->caml.x);
		fdf->cam.y -= 0.5 * cosf(fdf->caml.z) * sinf(fdf->caml.x);
		fdf->cam.z += 0.5 * cosf(fdf->caml.x);
	}
	if (keycode == 2)
	{
		fdf->cam.x -= 0.5 * cosf(fdf->caml.z);
		fdf->cam.y -= 0.5 * sinf(fdf->caml.z);
	}
	ft_keycom3(keycode, fdf);
}

void			ft_keycom1(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (keycode == 52)
		fdf->caml.z -= 0.01;
	if (keycode == 51)
		fdf->caml.y -= 0.01;
	if (keycode == 50)
		fdf->caml.x -= 0.01;
	if (keycode == 126)
		fdf->caml.x += 0.01;
	if (keycode == 125)
		fdf->caml.x -= 0.01;
	if (keycode == 123)
		fdf->caml.y -= 0.01;
	if (keycode == 124)
		fdf->caml.y += 0.01;
	if (keycode == 12)
		fdf->caml.z += 0.01;
	if (keycode == 14)
		fdf->caml.z -= 0.01;
	ft_keycom2(keycode, fdf);
}

int				ft_keyread(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	ft_keycom1(keycode, fdf);
	return (0);
}
