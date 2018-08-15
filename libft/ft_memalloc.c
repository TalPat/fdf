/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:49:29 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/30 11:32:10 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	int		i;

	i = 0;
	mem = malloc(size);
	if (mem)
	{
		while (size - i > 0)
		{
			((char*)mem)[i] = 0;
			i++;
		}
	}
	return (mem);
}
