/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildlinks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 19:02:40 by talon             #+#    #+#             */
/*   Updated: 2018/08/21 09:18:06 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	ft_buildlinks(t_fdf *fdf)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;
	t_list	*linktmp;

	tmp = fdf->perslist;
	i = 0;
	j = 0;
	while (tmp)
	{
		if (j < fdf->maph)
		{
			linktmp = tmp;
			k = fdf->mapw;
			while (linktmp && k >= 0)
			{
				linktmp = linktmp->next;
				k--;
			}
			((t_vect*)(tmp->content))->link2 = linktmp->content;
		}
		else
			((t_vect*)(tmp->content))->link2 = NULL;
		if (i < fdf->mapw)
			((t_vect*)(tmp->content))->link1 = tmp->next->content;
		else
		{
			j++;
			i = -1;
			((t_vect*)(tmp->content))->link1 = NULL;
		}
		i++;
		tmp = tmp->next;
	}
}
