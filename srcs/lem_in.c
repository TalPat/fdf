/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:07:06 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/09 16:53:29 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

void	ft_initialise(t_lem *lem)
{
	lem->start = NULL;
	lem->end = NULL;
	lem->roomname = NULL;
	lem->antno = 0;
	lem->err = 0;
	lem->roomno = 0;
	ft_readmap(lem);
	ft_delcomments(lem);
	ft_getant(lem);
	ft_assstart(lem);
	ft_assend(lem);
	ft_buildrooms(lem);
	ft_buildlinks(lem);
	if (ft_lstlen(lem->map) > 0)
		lem->err = 1;
}

int		main(void)
{
	t_lem	*lem;
	int		i;

	i = 0;
	lem = (t_lem*)malloc(sizeof(t_lem));
	ft_initialise(lem);
	if (lem->err)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	ft_findpath(lem);
	if (lem->path[0])
	{
		i = 0;
		while (lem->charmap[i])
			ft_putendl(lem->charmap[i++]);
		ft_printcom(lem);
	}
	return (0);
}
