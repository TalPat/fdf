/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildrooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:48:11 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 13:36:00 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int		ft_roomno(t_lem *lem)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = lem->map;
	while (tmp)
	{
		if (ft_validroom(tmp->content))
			count++;
		else
			break ;
		tmp = tmp->next;
	}
	lem->roomno = count;
	return (count);
}

void	ft_assnames(t_lem *lem)
{
	t_list	*tmp;
	int		i;
	char	**split;

	lem->roomname = (char**)malloc(sizeof(char*) * (lem->roomno + 1));
	lem->roomname[lem->roomno] = NULL;
	i = 0;
	tmp = lem->map;
	while (tmp)
	{
		if (ft_validroom(tmp->content))
		{
			split = ft_strsplit(tmp->content, ' ');
			lem->roomname[i] = ft_strdup(split[0]);
		}
		else
			break ;
		tmp = tmp->next;
		i++;
	}
}

void	ft_buildrooms(t_lem *lem)
{
	int		roomno;
	int		i;
	t_list	*tmp;

	tmp = lem->map;
	i = 0;
	roomno = ft_roomno(lem);
	ft_assnames(lem);
	lem->rooms = (char**)malloc(sizeof(char*) * (roomno + 1));
	lem->rooms[roomno] = NULL;
	while (tmp)
	{
		if (ft_validroom(tmp->content))
		{
			lem->rooms[i] = ft_strdup(tmp->content);
			ft_lstremove(tmp, NULL, lem);
		}
		else
			break ;
		tmp = tmp->next;
		i++;
	}
}
