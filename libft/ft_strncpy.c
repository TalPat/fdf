/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:33:33 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/21 13:42:25 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;
	int end;

	end = 0;
	i = 0;
	while (len - i > 0)
	{
		if (src[i] && end == 0)
			dst[i] = src[i];
		else
			end = 1;
		if (end == 1)
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
