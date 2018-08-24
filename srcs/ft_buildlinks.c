/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildlinks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 19:02:40 by talon             #+#    #+#             */
/*   Updated: 2018/08/24 13:22:29 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	ft_travlist(t_list **lst, int amount)
{
	while (*lst && amount >= 0)
	{
		*lst = (*lst)->next;
		amount--;
	}
}

void	ft_normsucks(int *i, int *j, t_list *tmp)
{
	(*j)++;
	*i = -1;
	((t_vect*)(tmp->content))->link1 = NULL;
}

void	ft_buildlinks(t_fdf *fdf)
{
	int		i;
	int		j;
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
			ft_travlist(&linktmp, fdf->mapw);
			((t_vect*)(tmp->content))->link2 = linktmp->content;
		}
		else
			((t_vect*)(tmp->content))->link2 = NULL;
		if (i < fdf->mapw)
			((t_vect*)(tmp->content))->link1 = tmp->next->content;
		else
			ft_normsucks(&i, &j, tmp);
		i++;
		tmp = tmp->next;
	}
}
