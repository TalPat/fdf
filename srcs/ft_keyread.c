/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:02:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/18 16:01:57 by talon            ###   ########.fr       */
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
	if (keycode == 65362)		//UP Z ANGLE UP
		fdf->caml.x += 0.01;
	if (keycode == 65364)
		fdf->caml.x -= 0.01;	//DOWN Z ANGLE DOWN
	if (keycode == 65361)
		fdf->caml.y -= 0.01;	//LEFT Y ANGLE UP
	if (keycode == 65363)
		fdf->caml.y += 0.01;	//RGIHT Y ANGLE UP
	if (keycode == 113)
		fdf->caml.z += 0.01;	//Q X ANGLE UP
	if (keycode == 101)
		fdf->caml.z -= 0.01;	//E X ANGLE UP
	if (keycode == 119)
		fdf->cam.y += 1;		//W Y TRANS
	if (keycode == 97)
		fdf->cam.x -= 1;		//A X TRANS
	if (keycode == 115)
		fdf->cam.y -= 1;		//S Y TRANS
	if (keycode == 100)
		fdf->cam.x += 1;		//D X TRANS
	if (keycode == 65505)
		fdf->cam.z += 1;		//SHIFT Z TRANS
	if (keycode == 65507)
		fdf->cam.z -= 1;		//LCTRL Z TRANS
	if (keycode == 45)
		fdf->disppos.z += 100;	//- FOCAL LENTH
	if (keycode == 61)
		fdf->disppos.z -= 100;	//= FOCAL LEN
	ft_putnbr(keycode);
	ft_putchar('\n');
	ft_putnbr(((t_vect*)fdf->perslist->content)->x);
	ft_putchar('\n');
	ft_putnbr(((t_vect*)fdf->perslist->content)->y);
	ft_putchar('\n');
	ft_putnbr(((t_vect*)fdf->perslist->content)->z);
	ft_putchar('\n');
	ft_render(fdf);
	return (0);
}
