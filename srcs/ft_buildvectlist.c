/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildvectlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:09:47 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/27 10:15:48 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

void	ft_cleanstuff(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_addtovlist(t_vect *myvect, int j, t_list **tmp, t_fdf *fdf)
{
	char	**vectc;
	int		i;
	t_list	*tmpend;

	vectc = ft_strsplit((*tmp)->content, ' ');
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
	ft_cleanstuff(vectc);
}

void	ft_errorcheck(t_fdf *fdf)
{
	t_list	*tmp;
	int		width;
	int		i;

	width = -1;
	tmp = fdf->vectlist;
	while (((t_vect*)(tmp->content))->x < ((t_vect*)(tmp->next->content))->x)
		tmp = tmp->next;
	width = ((t_vect*)(tmp->content))->x;
	while (tmp->next)
	{
		i = 0;
		while (i <= width && tmp)
		{
			i++;
			tmp = tmp->next;
		}
		if (width != ((t_vect*)(tmp->content))->x)
		{
			fdf->error = 2;
			break ;
		}
	}
}

void	ft_buildvectlist(t_fdf *fdf)
{
	int		j;
	t_vect	*myvect;
	t_list	*tmp;

	tmp = fdf->maplist;
	myvect = (t_vect*)malloc(sizeof(t_vect));
	j = 0;
	while (tmp)
	{
		ft_addtovlist(myvect, j, &tmp, fdf);
		j++;
		tmp = tmp->next;
	}
	ft_errorcheck(fdf);
}
