/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatepers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 22:21:05 by talon             #+#    #+#             */
/*   Updated: 2018/08/24 14:21:23 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

float	ft_dox(t_vect *v, t_fdf *fdf)
{
	float	sy;
	float	sz;
	float	cy;
	float	cz;

	sy = sinf(fdf->caml.y);
	sz = sinf(fdf->caml.z);
	cy = cosf(fdf->caml.y);
	cz = cosf(fdf->caml.z);
	return (cy * (sz * (v->y - fdf->cam.y) + cz * (v->x - fdf->cam.x)) - sy
			* (v->z - fdf->cam.z));
}

float	ft_doy(t_vect *v, t_fdf *fdf)
{
	float	sy;
	float	sz;
	float	cy;
	float	cz;

	sy = sinf(fdf->caml.y);
	sz = sinf(fdf->caml.z);
	cy = cosf(fdf->caml.y);
	cz = cosf(fdf->caml.z);
	return (sinf(fdf->caml.x) * (cy * (v->z - fdf->cam.z) + sy
	* (sz * (v->y - fdf->cam.y) + cz * (v->x - fdf->cam.x)))
	+ cosf(fdf->caml.x) * (cz * (v->y - fdf->cam.y) - sz
	* (v->x - fdf->cam.x)));
}

float	ft_doz(t_vect *v, t_fdf *fdf)
{
	float	sy;
	float	sz;
	float	cy;
	float	cz;

	sy = sinf(fdf->caml.y);
	sz = sinf(fdf->caml.z);
	cy = cosf(fdf->caml.y);
	cz = cosf(fdf->caml.z);
	return (cosf(fdf->caml.x) * (cy * (v->z - fdf->cam.z) + sy
	* (sz * (v->y - fdf->cam.y) + cz * (v->x - fdf->cam.x)))
	- sinf(fdf->caml.x) * (cz * (v->y - fdf->cam.y) - sz
	* (v->x - fdf->cam.x)));
}

int		ft_infront(t_vect *vect, t_fdf *fdf)
{
	t_vect	delta;
	t_vect	deg;
	float	dist;
	float	hdev;
	float	vdev;

	delta.x = (fdf->cam.x) - vect->x;
	delta.y = (fdf->cam.y) - vect->y;
	delta.z = (fdf->cam.z) - vect->z;
	dist = sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
	deg.x = acosf(delta.z / dist);
	deg.z = acosf(delta.x / sqrtf(delta.x * delta.x + delta.y * delta.y));
	if (fdf->cam.y < vect->y)
		deg.z = 2 * M_PI - deg.z;
	hdev = fdf->caml.z - M_PI / 2 - deg.z;
	vdev = fdf->caml.x - deg.x;
	if (hdev < -1 * M_PI)
		hdev += 2 * M_PI;
	if (hdev > M_PI / 2 || hdev < -1 * M_PI / 2)
		return (0);
	hdev = atanf(sqrtf(fdf->width) * sqrtf(fdf->width) + sqrtf(fdf->height)
				* sqrtf(fdf->height) / 2 / fdf->disppos.z);
	if ((vdev > hdev || vdev < (-1 * hdev)))
		return (0);
	return (1);
}

void	ft_updatepers(t_fdf *fdf)
{
	t_list	*tmp;
	t_list	*tmppers;
	t_vect	dval;

	tmp = fdf->vectlist;
	tmppers = fdf->perslist;
	while (tmp)
	{
		((t_vect*)tmppers->content)->x = -1;
		((t_vect*)tmppers->content)->y = -1;
		if (ft_infront(tmp->content, fdf))
		{
			dval.x = ft_dox(((t_vect*)tmp->content), fdf);
			dval.y = ft_doy(((t_vect*)tmp->content), fdf);
			dval.z = ft_doz(((t_vect*)tmp->content), fdf);
			((t_vect*)tmppers->content)->x = (fdf->disppos.z / dval.z) * dval.x
											+ fdf->disppos.x;
			((t_vect*)tmppers->content)->y = (fdf->disppos.z / dval.z) * dval.y
											+ fdf->disppos.y;
		}
		tmp = tmp->next;
		tmppers = tmppers->next;
	}
}
