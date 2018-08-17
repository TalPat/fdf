/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatepers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 22:21:05 by talon             #+#    #+#             */
/*   Updated: 2018/08/17 23:26:12 by talon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

float	ft_dox(t_vect* v, t_fdf *fdf)
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

float	ft_doy(t_vect* v, t_fdf *fdf)
{
	float	sy;
	float	sz;
	float	cy;
	float	cz;

	sy = sinf(fdf->caml.y);
	sz = sinf(fdf->caml.z);
	cy = cosf(fdf->caml.y);
	cz = cosf(fdf->caml.z);
	return (sinf(fdf->caml.x) * (cy * (v->z - fdf->cam.z) + sy * (sz * (v->y - fdf->cam.y)
			+ cz * (v->x - fdf->cam.x))) + cosf(fdf->caml.x) * (cz * (v->y - fdf->cam.y)
			- sz * (v->x - fdf->cam.x)));
}

float	ft_doz(t_vect* v, t_fdf *fdf)
{
	float	sy;
	float	sz;
	float	cy;
	float	cz;

	sy = sinf(fdf->caml.y);
	sz = sinf(fdf->caml.z);
	cy = cosf(fdf->caml.y);
	cz = cosf(fdf->caml.z);
	return (cosf(fdf->caml.x) * (cy * (v->z - fdf->cam.z) + sy * (sz * (v->y - fdf->cam.y)
			+ cz * (v->x - fdf->cam.x))) - sinf(fdf->caml.x) * (cz * (v->y - fdf->cam.y)
			- sz * (v->x - fdf->cam.x)));
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
		dval.x = ft_dox(((t_vect*)tmp->content), fdf);
		dval.y = ft_doy(((t_vect*)tmp->content), fdf);
		dval.z = ft_doz(((t_vect*)tmp->content), fdf);
		((t_vect*)tmppers->content)->x = (fdf->disppos.z / dval.z) * dval.x
										+ fdf->disppos.x;
		((t_vect*)tmppers->content)->y = (fdf->disppos.z / dval.z) * dval.y
										+ fdf->disppos.y;
		tmp = tmp->next;
		tmppers = tmppers->next;
	}
}
