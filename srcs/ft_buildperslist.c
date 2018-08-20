/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildperslist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:04:55 by talon             #+#    #+#             */
/*   Updated: 2018/08/20 10:25:30 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include "mlx.h"

void	ft_buildperslist(t_fdf *fdf)
{
	t_list	*tmp;

	tmp = fdf->vectlist;
	fdf->perslist = ft_lstnew(tmp->content, sizeof(t_vect));
	tmp = tmp->next;
	while (tmp)
	{
		fdf->mapw = ((t_vect*)tmp->content)->x;
		fdf->maph = ((t_vect*)tmp->content)->y;
		fdf->cam.x = fdf->mapw / 2;
		fdf->cam.y = fdf->maph / 2;
		ft_lstaddend(fdf->perslist, tmp->content, sizeof(t_vect));
		tmp = tmp->next;
	}
}
