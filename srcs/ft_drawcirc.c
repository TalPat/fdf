/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawcirc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:41:04 by talon             #+#    #+#             */
/*   Updated: 2018/08/17 20:46:40 by talon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"

void	ft_drawcirc(float cx, float cy, float r, t_fdf *fdf)
{
	t_vect	*vect;

	vect = (t_vect*)malloc(sizeof(t_vect));
	vect->x = cx - r;
	while (vect->x <= cx + r)
	{
		vect->y = sqrtf((r * r) - ((vect->x - cx) * (vect->x - cx))) + cy;
		ft_drawtoimg(vect, fdf->img);
		vect->y = cy - (vect->y - cy);
		ft_drawtoimg(vect, fdf->img);
		vect->x++;
	}
	vect->y = cy - r;
	while (vect->y <= cy + r)
	{
		vect->x = sqrtf((r * r) - ((vect->y - cy) * (vect->y - cy))) + cx;
		ft_drawtoimg(vect, fdf->img);
		vect->x = -sqrtf((r * r) - ((vect->y - cy) * (vect->y - cy))) + cx;
		ft_drawtoimg(vect, fdf->img);
		vect->y++;
	}
}
