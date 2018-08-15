/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:59:32 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/22 13:56:32 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)(haystack));
	while (haystack[i] && len - i > 0)
	{
		check = 1;
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j])
			{
				if (needle[j] != haystack[i + j] || len - (i + j) == 0)
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
