/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:45:03 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/23 18:54:57 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	int				i;
	unsigned char	*newsrc;
	unsigned char	*newdst;

	newsrc = (unsigned char*)src;
	newdst = (unsigned char*)dst;
	i = 0;
	while (n - i > 0)
	{
		newdst[i] = newsrc[i];
		if (newsrc[i] == (unsigned char)(c))
		{
			i++;
			return (newdst + i);
		}
		i++;
	}
	return (NULL);
}
