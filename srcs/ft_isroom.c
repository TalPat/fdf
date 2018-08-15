/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:36:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 13:40:18 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int	ft_isroom(char *str, t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->roomname[i])
	{
		if (!ft_strcmp(str, lem->roomname[i]))
			return (1);
		i++;
	}
	return (0);
}
