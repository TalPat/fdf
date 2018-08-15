/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 10:30:10 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 14:14:27 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int		ft_numends(t_list *map)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = map;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "##end"))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_assandremend(t_lem *lem)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = lem->map;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "##end"))
		{
			ft_lstremove(tmp, prev, lem);
			tmp = tmp->next;
			if (ft_validroom(tmp->content))
				lem->end = ft_strdup(tmp->content);
			else
			{
				lem->end = NULL;
				lem->err = 1;
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	ft_assend(t_lem *lem)
{
	int		numends;

	numends = ft_numends(lem->map);
	if (numends != 1)
	{
		lem->err = 1;
		lem->end = NULL;
	}
	else
	{
		ft_assandremend(lem);
	}
}
