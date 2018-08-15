/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:28:33 by talon             #+#    #+#             */
/*   Updated: 2018/08/15 15:42:07 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include "fdf.h"

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
		while (fdf->maplist)
		{
			ft_putendl(fdf->maplist->content);
			fdf->maplist = fdf->maplist->next;
		}
	}
	return (0);
}
