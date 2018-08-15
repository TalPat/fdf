/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:39:53 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/30 11:34:02 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char const	*ft_start(char const *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (s + i);
}

static char const	*ft_end(char const *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	return (s + i);
}

char				*ft_strtrim(char const *s)
{
	char	*fresh;
	int		i;

	i = 0;
	if (s)
	{
		if (ft_end(s) - ft_start(s) + 1 <= 0)
		{
			fresh = (char*)malloc(sizeof(char));
			*fresh = '\0';
			return (fresh);
		}
		fresh = (char*)malloc(sizeof(char) * (ft_end(s) - ft_start(s) + 1 + 1));
		if (fresh)
		{
			while (i < ft_end(s) - ft_start(s) + 1)
			{
				fresh[i] = ft_start(s)[i];
				i++;
			}
			fresh[i] = '\0';
		}
		return (fresh);
	}
	return (NULL);
}
