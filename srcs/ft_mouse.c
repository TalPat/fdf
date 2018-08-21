/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:47:30 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/21 08:42:52 by tpatter          ###   ########.fr       */
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
	//mouse change in x
	fdf->caml.z -= (float)(fdf->mousex - x) * 0.005;
	//mouse change in y
	fdf->caml.x += (float)(fdf->mousey - y) * 0.005;
	fdf->mousex = x;
	fdf->mousey = y;
	if (fdf->caml.x < 0)
		fdf->caml.x = 0;
	if (fdf->caml.x > M_PI)
		fdf->caml.x = M_PI;
	//ft_render(fdf);
	return (0);
}
