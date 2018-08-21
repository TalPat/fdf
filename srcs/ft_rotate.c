/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:40:32 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/21 12:04:21 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

int	ft_rotate(void *param)
{
	t_list	*tmp;
	t_vect	*vect;
	t_vect	vtmp;
	t_fdf	*fdf;

	fdf = param;
	if (fdf->rotate)
	{
		tmp = fdf->vectlist;
		while (tmp)
		{
			vect = ((t_vect*)tmp->content);
			vect->x -= fdf->mapw / 2;
			vect->y -= fdf->maph / 2;
			vtmp = *vect;
			vect->x = vtmp.x * cosf(0.001) - vtmp.y * sinf(0.001);
			vect->y = vtmp.y * cosf(0.001) + vtmp.x * sinf(0.001);
			vect->x += fdf->mapw / 2;
			vect->y += fdf->maph / 2;
			tmp = tmp->next;
		}
	}
	return (0);
}
