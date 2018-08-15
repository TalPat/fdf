/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildlinks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:18:44 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 14:09:03 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int		ft_linkno(t_lem *lem)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = lem->map;
	while (tmp)
	{
		if (ft_validlink(tmp->content, lem))
			count++;
		else
			break ;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_buildlinks(t_lem *lem)
{
	int		linkno;
	int		i;
	t_list	*tmp;

	tmp = lem->map;
	i = 0;
	linkno = ft_linkno(lem);
	lem->links = (char**)malloc(sizeof(char*) * (linkno + 1));
	lem->links[linkno] = NULL;
	while (tmp)
	{
		if (ft_validlink(tmp->content, lem))
		{
			lem->links[i] = ft_strdup(tmp->content);
			ft_lstremove(tmp, NULL, lem);
		}
		else
			break ;
		tmp = tmp->next;
		i++;
	}
}
