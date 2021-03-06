/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:28:33 by talon             #+#    #+#             */
/*   Updated: 2018/08/27 10:17:51 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include <stdio.h>

void	ft_initfdf(t_fdf *fdf, char *dir)
{
	ft_putendl("initialising");
	fdf->img = (t_image*)malloc(sizeof(t_image));
	fdf->mapdir = dir;
	fdf->mlx = mlx_init();
	fdf->width = 1366;
	fdf->height = 720;
	fdf->img->width = fdf->width;
	fdf->img->height = fdf->height;
	fdf->cam.z = 50;
	fdf->caml.x = 0.5;
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
	fdf->error = 0;
	fdf->rowlen = 0;
	if (ft_strcmp(".fdf", dir + ft_strlen(dir) - 4))
		fdf->error = 1;
}

void	ft_errorquit(t_fdf *fdf)
{
	if (fdf->error == 1)
		ft_putendl("Submitted map must be *.fdf format");
	else
		ft_putendl("Map content is invalid");
	exit(0);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		ft_putendl("Usage : ./fdf <filename>");
	else
	{
		fdf = (t_fdf*)malloc(sizeof(t_fdf));
		ft_initfdf(fdf, av[1]);
		ft_putendl("reading map");
		ft_readmap(fdf);
		if (fdf->error)
			ft_errorquit(fdf);
		ft_putendl("building vector list");
		ft_buildvectlist(fdf);
		if (fdf->error)
			ft_errorquit(fdf);
		ft_putendl("building perspective list");
		ft_buildperslist(fdf);
		ft_buildlinks(fdf);
		mlx_hook(fdf->win, 2, 0, ft_keyread, fdf);
		mlx_hook(fdf->win, 6, 0, ft_mouse, fdf);
		mlx_loop_hook(fdf->mlx, ft_renderhook, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
