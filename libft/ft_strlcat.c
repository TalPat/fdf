/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:07:12 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/23 19:13:08 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		dstlen;
	int		newdstsize;

	newdstsize = dstsize;
	i = 0;
	dstlen = ft_strlen(dst);
	while (i < (newdstsize - dstlen - 1) && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstsize != 0 && !(dstlen > newdstsize))
	{
		dst[dstlen + i] = '\0';
		return (dstlen + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
