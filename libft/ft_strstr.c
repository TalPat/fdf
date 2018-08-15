/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:35:11 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/22 13:55:31 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)(haystack));
	while (haystack[i])
	{
		check = 1;
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j])
			{
				if (needle[j] != haystack[i + j])
					check = 0;
				j++;
			}
			if (check == 1)
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
