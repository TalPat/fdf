/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:28:33 by talon             #+#    #+#             */
/*   Updated: 2018/08/16 13:16:48 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include <stdio.h>

void	ft_initfdf(t_fdf *fdf, char *dir)
{
	fdf->mapdir = dir;
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
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, 400, 400, "FDF");
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
