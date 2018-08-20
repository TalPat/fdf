/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:02:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/20 13:02:53 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int				ft_keyread(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (keycode == 52)			//5 EXIT
		fdf->caml.z -= 0.01;
	if (keycode == 51)		
		fdf->caml.y -= 0.01;
	if (keycode == 50)
		fdf->caml.x -= 0.01;
	if (keycode == 126)		//UP Z ANGLE UP
		fdf->caml.x += 0.01;
	if (keycode == 125)
		fdf->caml.x -= 0.01;	//DOWN Z ANGLE DOWN
	if (keycode == 123)
		fdf->caml.y -= 0.01;	//LEFT Y ANGLE UP
	if (keycode == 124)
		fdf->caml.y += 0.01;	//RGIHT Y ANGLE UP
	if (keycode == 12)
		fdf->caml.z += 0.01;	//Q X ANGLE UP
	if (keycode == 14)
		fdf->caml.z -= 0.01;	//E X ANGLE UP
	if (keycode == 13)
		fdf->cam.y += 0.1;		//W Y TRANS
	if (keycode == 0)
		fdf->cam.x -= 0.1;		//A X TRANS
	if (keycode == 1)
		fdf->cam.y -= 0.1;		//S Y TRANS
	if (keycode == 2)
		fdf->cam.x += 0.1;		//D X TRANS
	if (keycode == 7)
		fdf->cam.z += 0.1;		//SHIFT Z TRANS
	if (keycode == 6)
		fdf->cam.z -= 0.1;		//LCTRL Z TRANS
	if (keycode == 27)
		fdf->disppos.z += 100;	//- FOCAL LENTH
	if (keycode == 24)
		fdf->disppos.z -= 100;	//= FOCAL LEN
	ft_putnbr(keycode);
	ft_putchar('\n');
	ft_render(fdf);
	return (0);
}
