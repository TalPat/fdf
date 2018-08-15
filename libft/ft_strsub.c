/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:11:42 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/30 11:32:48 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (s)
	{
		sub = (char*)malloc(sizeof(char) * (len + 1));
		if (sub)
		{
			while (len - i > 0)
			{
				sub[i] = s[start + i];
				i++;
			}
			sub[i] = '\0';
		}
		return (sub);
	}
	return (NULL);
}
