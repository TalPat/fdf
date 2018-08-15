/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlinks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:15:04 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/09 14:16:04 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

void	ft_getlinks(t_lem *lem, char *cur)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	while (lem->curlinks[i])
		lem->curlinks[i++] = NULL;
	i = 0;
	while (lem->links[i])
	{
		split = ft_strsplit(lem->links[i], '-');
		if ((!ft_strcmp(cur, split[0]) || !ft_strcmp(cur, split[1]))
			&& !ft_visited(lem, split[0], split[1]))
		{
			if (!ft_strcmp(cur, split[0]))
				lem->curlinks[j] = split[1];
			if (!ft_strcmp(cur, split[1]))
				lem->curlinks[j] = split[0];
			j++;
		}
		i++;
	}
}
