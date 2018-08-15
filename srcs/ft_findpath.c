/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:08:03 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/09 14:32:46 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

void	ft_instpath(t_lem *lem)
{
	int	i;

	i = 0;
	lem->path = (char**)malloc(sizeof(char*) * (lem->roomno + 1));
	lem->visited = (char**)malloc(sizeof(char*) * (lem->roomno + 1));
	lem->curlinks = (char**)malloc(sizeof(char*) * (lem->roomno) + 1);
	while (i <= lem->roomno)
	{
		lem->curlinks[i] = NULL;
		lem->path[i] = NULL;
		lem->visited[i] = NULL;
		i++;
	}
	lem->startname = ft_strsplit(lem->start, ' ')[0];
	lem->endname = ft_strsplit(lem->end, ' ')[0];
	lem->path[0] = lem->startname;
	lem->curroom = lem->startname;
	lem->found = 0;
}

int		ft_visited(t_lem *lem, char *r1, char *r2)
{
	int	i;
	int	count1;
	int	count2;

	i = 0;
	count1 = 0;
	count2 = 0;
	while (lem->visited[i])
	{
		if (!ft_strcmp(r1, lem->visited[i]))
			count1 = 1;
		if (!ft_strcmp(r2, lem->visited[i]))
			count2 = 1;
		i++;
	}
	if (count1 + count2 == 2)
		return (1);
	return (0);
}

int		ft_goback(t_lem *lem, int index)
{
	int	i;

	i = 0;
	while (lem->path[i])
		i++;
	if (i)
		lem->path[i - 1] = NULL;
	if (i > 1)
		lem->curroom = lem->path[i - 2];
	return (index - 1);
}

void	ft_findpath(t_lem *lem)
{
	int		i;

	i = 0;
	ft_instpath(lem);
	while (!lem->found)
	{
		if (!ft_visited(lem, lem->curroom, lem->curroom))
			ft_stradd(lem->curroom, lem->visited);
		ft_getlinks(lem, lem->curroom);
		if (lem->curlinks[0])
		{
			lem->curroom = lem->curlinks[0];
			i++;
			lem->path[i] = lem->curroom;
			if (!ft_strcmp(lem->curroom, lem->endname))
				lem->found = 1;
		}
		else
			i = ft_goback(lem, i);
		if (!lem->path[0])
		{
			ft_putendl("NO SOLUTION");
			break ;
		}
	}
}
