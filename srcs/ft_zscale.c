/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:39:36 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/21 09:51:39 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>

void	ft_zscale(float scale, t_fdf *fdf)
{
	t_list	*tmp;
	t_list	*tmppers;

	tmp = fdf->vectlist;
	tmppers = fdf->perslist;
	while (tmp)
	{
		((t_vect*)tmp->content)->z *= scale;
		((t_vect*)tmppers->content)->z *= scale;
		tmp = tmp->next;
		tmppers = tmppers->next;
	}
}
