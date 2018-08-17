/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:28:33 by talon             #+#    #+#             */
/*   Updated: 2018/08/17 23:49:55 by talon            ###   ########.fr       */
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
	fdf->width = 1366;
	fdf->height = 720;
	fdf->img->width = fdf->width;
	fdf->img->height = fdf->height;
	fdf->cam.x = fdf->width / 2;
	fdf->cam.y = fdf->height / 2;
	fdf->cam.z = 5;
	fdf->caml.x = 0;
	fdf->caml.y = 0;
	fdf->caml.z = 0;
	fdf->disppos.x = fdf->width / 2;
	fdf->disppos.y = fdf->height / 2;
	fdf->disppos.z = 1;
	fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->height, "FDF");
	fdf->img->image = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
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
		ft_readmap(fdf);
		ft_buildvectlist(fdf);
		ft_buildperslist(fdf);		ft_render(fdf);
		mlx_key_hook(fdf->win, ft_keyread, fdf);
		mlx_loop(fdf->mlx);
		while (fdf->maplist)
		{
			ft_putendl(fdf->maplist->content);
			fdf->maplist = fdf->maplist->next;
		}
		int	i = 1;
		while (fdf->vectlist)
		{
			printf("%f ", ((t_vect*)(fdf->vectlist->content))->z);
			fdf->vectlist = fdf->vectlist->next;
			if (i % 19 == 0)
			{
				printf("\n");
				i = 0;
			}
			i++;
		}
	}
	return (0);
}
