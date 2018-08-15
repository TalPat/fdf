/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validroom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:34:12 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 11:46:27 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int	ft_validroom(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
		i++;
	if (i != 3)
		return (0);
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	if (!ft_isnum(split[1]) || !ft_isnum(split[2]))
		return (0);
	return (1);
}
