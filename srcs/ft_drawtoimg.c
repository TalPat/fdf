/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtoimg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:46:33 by talon             #+#    #+#             */
/*   Updated: 2018/08/24 13:57:20 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_drawtoimgcol(t_vect *point, t_image *img, unsigned int col)
{
	unsigned int	*i;
	int				index;

	index = ((int)(point->x)) + (((int)point->y) * img->s_l / 4);
	i = (unsigned int*)img->imgdata;
	if (point->x >= 0 && point->x < img->width && point->y >= 0
		&& point->y < img->height)
		i[index] = col;
}

void	ft_drawtoimg(t_vect *point, t_image *img)
{
	unsigned int	*i;
	int				index;

	index = ((int)(point->x)) + (((int)point->y) * img->s_l / 4);
	i = (unsigned int*)img->imgdata;
	if (point->x >= 0 && point->x < img->width && point->y >= 0
		&& point->y < img->height)
		i[index] = 0xffffff - 0x00ffff * (point->z / 20);
}
