/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:47:30 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/20 17:13:11 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

int	ft_mouse(int x, int y, t_fdf *fdf)
{
	if (fdf->mousex == -20000 || fdf->mousey == -20000)
	{
		fdf->mousex = x;
		fdf->mousey = y;
	}
	//fdf->caml.x += (float)(y - fdf->mousey) * 0.005 * sinf(fdf->caml.y);
	//fdf->caml.y += (float)(x - fdf->mousex) * 0.005 * cosf(fdf->caml.y);

	//fdf->caml.x += (float)(y - fdf->mousey) * 0.005 * cosf(fdf->caml.y);
	//fdf->caml.y += (float)(x - fdf->mousex) * 0.005 * sinf(fdf->caml.y);

	//mouse change in x
	//fdf->caml.x += (float)(fdf->mousex - x) * 0.005 * (cosf(fdf->caml.z) * cosf(fdf->caml.y) - sinf(fdf->caml.z) * sinf(fdf->caml.y));
	fdf->caml.y += (float)(fdf->mousex - x) * 0.005 * (cosf(fdf->caml.z) * cosf(fdf->caml.x) - sinf(fdf->caml.z) * sinf(fdf->caml.x));
	fdf->caml.z += (float)(fdf->mousex - x) * 0.005 * (cosf(fdf->caml.y) * cosf(fdf->caml.x) - sinf(fdf->caml.y) * sinf(fdf->caml.x));

	fdf->mousex = x;
	fdf->mousey = y;
	ft_render(fdf);
	return (0);
}
