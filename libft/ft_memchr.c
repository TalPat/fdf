/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:43:08 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/24 13:36:10 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*news;

	news = (unsigned char*)s;
	i = 0;
	while (n - i > 0)
	{
		if (news[i] == (unsigned char)c)
			return (news + i);
		i++;
	}
	return (NULL);
}
