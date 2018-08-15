/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 10:39:19 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 11:00:11 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

void	ft_getant(t_lem *lem)
{
	if (ft_isnum(lem->map->content))
	{
		lem->antno = ft_atoi(lem->map->content);
		ft_lstremove(lem->map, NULL, lem);
	}
	else
		lem->err = 1;
}
