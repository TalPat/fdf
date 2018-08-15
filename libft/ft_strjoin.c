/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:24:42 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/30 11:33:34 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;

	fresh = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (fresh)
	{
		i = 0;
		while (s1[i])
		{
			fresh[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i])
		{
			fresh[ft_strlen(s1) + i] = s2[i];
			i++;
		}
		fresh[ft_strlen(s1) + i] = '\0';
	}
	return (fresh);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strjoin2(s1, s2));
	return (NULL);
}
