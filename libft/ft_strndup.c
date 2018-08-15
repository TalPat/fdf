/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:27:55 by tpatter           #+#    #+#             */
/*   Updated: 2018/06/25 16:34:26 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, int n)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = ft_strnew(n + 1);
	if (newstr)
	{
		while (s1[i] && i < n)
		{
			newstr[i] = s1[i];
			i++;
		}
	}
	return (newstr);
}
