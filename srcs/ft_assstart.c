/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:04:08 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 14:16:15 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int		ft_numstarts(t_list *map)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = map;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "##start"))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_assandrem(t_lem *lem)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = lem->map;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "##start"))
		{
			ft_lstremove(tmp, prev, lem);
			tmp = tmp->next;
			if (ft_validroom(tmp->content))
				lem->start = ft_strdup(tmp->content);
			else
			{
				lem->start = NULL;
				lem->err = 1;
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	ft_assstart(t_lem *lem)
{
	int		numstarts;

	numstarts = ft_numstarts(lem->map);
	if (numstarts != 1)
	{
		lem->err = 1;
		lem->start = NULL;
	}
	else
	{
		ft_assandrem(lem);
	}
}
