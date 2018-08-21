/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildvectlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:09:47 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/21 09:28:06 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

void	ft_buildvectlist(t_fdf *fdf)
{
	char	**vectc;
	int		i;
	int		j;
	t_vect	*myvect;
	t_list	*tmp;
	t_list	*tmpend;

	tmp = fdf->maplist;
	myvect = (t_vect*)malloc(sizeof(t_vect));
	j = 0;
	while (tmp)
	{
		vectc = ft_strsplit(tmp->content, ' ');
		i = 0;
		while (vectc[i])
		{
			myvect->x = i;
			myvect->y = j;
			myvect->z = ft_atoi(vectc[i]);
			if (i == 0 && j == 0)
			{
				fdf->vectlist = ft_lstnew(myvect, sizeof(t_vect));
				tmpend = fdf->vectlist;
			}
			else
			{
				while (tmpend->next)
					tmpend = tmpend->next;
				ft_lstaddend(tmpend, myvect, sizeof(t_vect));
			}
			i++;
		}
		tmp = tmp->next;
		j++;
	}
}
