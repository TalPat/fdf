/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:24:13 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/08 13:24:13 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int	ft_validlink(char *str, t_lem *lem)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(str, '-');
	while (split[i])
		i++;
	if (i != 2)
		return (0);
	if (!ft_isroom(split[0], lem) || !ft_isroom(split[1], lem))
		return (0);
	return (1);
}
