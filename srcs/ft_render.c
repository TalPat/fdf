/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:52:50 by talon             #+#    #+#             */
/*   Updated: 2018/08/17 23:47:23 by talon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_drawpoints(t_fdf *fdf)
{
	t_list	*tmp;

	tmp = fdf->perslist;
	fdf->img->imgdata = mlx_get_data_addr(fdf->img->image, &(fdf->img->bits),
								&(fdf->img->s_l), &(fdf->img->endian));
	while (tmp)
	{
		ft_drawtoimg(tmp->content, fdf->img);
		tmp = tmp->next;
	}
	/**/ft_drawcirc(fdf->width / 2, fdf->height / 2, 100, fdf);
}

void	ft_render(t_fdf *fdf)
{
	ft_updatepers(fdf);
	ft_drawpoints(fdf);
	//ft_connectpoints(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->image, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img->image);
	fdf->img->image = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
}