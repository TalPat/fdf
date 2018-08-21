/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:28:33 by talon             #+#    #+#             */
/*   Updated: 2018/08/21 11:08:48 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include <stdio.h>

void	ft_initfdf(t_fdf *fdf, char *dir)
{
	fdf->img = (t_image*)malloc(sizeof(t_image));
	fdf->mapdir = dir;
	fdf->mlx = mlx_init();
	fdf->width = 2140;
	fdf->height = 1080;
	fdf->img->width = fdf->width;
	fdf->img->height = fdf->height;
	fdf->cam.z = 50;
	fdf->caml.x = 0;
	fdf->caml.y = 0;
	fdf->caml.z = M_PI;
	fdf->disppos.x = fdf->width / 2;
	fdf->disppos.y = fdf->height / 2;
	fdf->disppos.z = 1000;
	fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->height, "FDF");
	fdf->img->image = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->mousex = -20000;
	fdf->mousey = -20000;
	fdf->rotate = 0;
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		ft_putendl("Usage : ./fdf <filename>");
	else
	{
		fdf = (t_fdf*)malloc(sizeof(t_fdf));
		/**/ft_putendl("initialising");
		ft_initfdf(fdf, av[1]);
		/**/ft_putendl("reading map");
		ft_readmap(fdf);
		/**/ft_putendl("building ve list");
		ft_buildvectlist(fdf);
		/**/ft_putendl("building pers list");
		ft_buildperslist(fdf);
		/**/ft_putendl("building links");
		ft_buildlinks(fdf);
		/**/ft_putendl("creating hooks");
		//mlx_key_hook(fdf->win, ft_keyread, fdf);
		mlx_hook(fdf->win, 2, 0, ft_keyread, fdf);
		mlx_hook(fdf->win, 6, 0, ft_mouse, fdf);
		//mlx_loop_hook(fdf->mlx, ft_rotate, fdf);
		mlx_loop_hook(fdf->mlx, ft_renderhook, fdf);
		//ft_render(fdf);
		mlx_loop(fdf->mlx);
		while (fdf->maplist)
		{
			ft_putendl(fdf->maplist->content);
			fdf->maplist = fdf->maplist->next;
		}
	}
	return (0);
}
