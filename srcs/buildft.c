/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:49:24 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/03 12:59:23 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

void	ft_lstremove(t_list *target, t_list *prev, t_lem *lem)
{
	t_list	*tmp;

	if (!prev)
	{
		tmp = (target)->next;
		free((target)->content);
		free(target);
		lem->map = tmp;
	}
	else
	{
		tmp = (target)->next;
		free((target)->content);
		free(target);
		prev->next = tmp;
	}
}

void	ft_delcomments(t_lem *lem)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = lem->map;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp((char*)(tmp->content), "##start")
		&& ft_strcmp((char*)(tmp->content), "##end")
		&& ((char*)(tmp->content))[0] == '#')
			ft_lstremove(tmp, prev, lem);
		else
			prev = tmp;
		tmp = tmp->next;
	}
}

void	ft_assignmap(t_lem *lem)
{
	t_list	*tmp;
	int		mapleng;
	int		i;

	i = 0;
	tmp = lem->map;
	mapleng = ft_lstlen(tmp);
	lem->charmap = (char**)malloc(sizeof(char*) * (mapleng + 1));
	lem->charmap[mapleng] = NULL;
	while (tmp)
	{
		lem->charmap[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
}
