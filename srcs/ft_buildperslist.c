/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildperslist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:04:55 by talon             #+#    #+#             */
/*   Updated: 2018/08/24 16:49:25 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include "mlx.h"

void	ft_buildperslist(t_fdf *fdf)
{
	t_list	*tmp;
	t_list	*tmpend;

	tmp = fdf->vectlist;
	fdf->perslist = ft_lstnew(tmp->content, sizeof(t_vect));
	tmpend = fdf->perslist;
	tmp = tmp->next;
	while (tmp)
	{
		while (tmpend->next)
			tmpend = tmpend->next;
		fdf->mapw = ((t_vect*)tmp->content)->x;
		fdf->maph = ((t_vect*)tmp->content)->y;
		fdf->cam.x = fdf->mapw / 2;
		fdf->cam.y = fdf->maph;
		ft_lstaddend(tmpend, tmp->content, sizeof(t_vect));
		tmp = tmp->next;
	}
}
