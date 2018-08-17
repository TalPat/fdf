/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtoimg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:46:33 by talon             #+#    #+#             */
/*   Updated: 2018/08/17 23:52:45 by talon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_drawtoimg(t_vect *point, t_image *img)
{
	unsigned int	*i;
	int				index;

	index = ((int)(point->x)) + (((int)point->y) * img->s_l / 4);
	i = (unsigned int*)img->imgdata;
	if (index >= 0 && index < (img->width * img->height))
		i[index] = 0xffffff - 0xff000 * (point->z / 10);
}