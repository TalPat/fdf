/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawlinecol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:00:31 by talon             #+#    #+#             */
/*   Updated: 2018/08/24 14:41:06 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

void	ft_mostlyhor(float grad, t_vect pointa, t_vect pointb, t_fdf *fdf)
{
	float	dif;

	dif = pointa.z - pointb.z;
	dif = -1 * dif / sqrtf((pointa.x - pointb.x) * (pointa.x - pointb.x));
	while (pointa.x - pointb.x > 0.5 || pointa.x - pointb.x < -0.5)
	{
		ft_drawtoimg(&pointa, fdf->img);
		if (pointa.x <= pointb.x)
		{
			pointa.y += grad;
			pointa.x++;
		}
		else
		{
			pointa.y -= grad;
			pointa.x--;
		}
		pointa.z += dif;
	}
	ft_drawtoimg(&pointa, fdf->img);
}

void	ft_mostlyver(t_vect pointa, t_vect pointb, t_fdf *fdf)
{
	float	dif;
	float	gradinv;

	dif = pointa.z - pointb.z;
	gradinv = (pointa.x - pointb.x) / (pointa.y - pointb.y);
	dif = -1 * dif / sqrtf((pointa.y - pointb.y) * (pointa.y - pointb.y));
	while (pointa.y - pointb.y > 0.5 || pointa.y - pointb.y < -0.5)
	{
		ft_drawtoimg(&pointa, fdf->img);
		if (pointa.y <= pointb.y)
		{
			pointa.x += gradinv;
			pointa.y++;
		}
		else
		{
			pointa.x -= gradinv;
			pointa.y--;
		}
		pointa.z += dif;
	}
	ft_drawtoimg(&pointa, fdf->img);
}

void	ft_vertical(t_vect pointa, t_vect pointb, t_fdf *fdf)
{
	if (pointa.y < pointb.y)
		while (pointa.y <= pointb.y)
		{
			ft_drawtoimg(&pointa, fdf->img);
			pointa.y++;
		}
	else
		while (pointa.y >= pointb.y)
		{
			ft_drawtoimg(&pointa, fdf->img);
			pointa.y--;
		}
}

void	ft_drawlinecol(t_vect pointa, t_vect pointb, t_fdf *fdf)
{
	float	grad;
	float	dif;

	if (pointa.x < 0 || pointa.x > fdf->width || pointa.y < 0 ||
		pointa.y > fdf->height || pointb.x < 0 || pointb.x > fdf->width ||
		pointb.y < 0 || pointb.y > fdf->height)
		return ;
	if (pointa.x == pointb.x)
		ft_vertical(pointa, pointb, fdf);
	else
	{
		grad = (pointa.y - pointb.y) / (pointa.x - pointb.x);
		dif = pointa.z - pointb.z;
		if (grad < 1 && grad > -1)
			ft_mostlyhor(grad, pointa, pointb, fdf);
		else
			ft_mostlyver(pointa, pointb, fdf);
	}
}
