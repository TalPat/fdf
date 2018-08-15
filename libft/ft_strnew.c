/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:20:15 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/30 11:31:39 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*mem;
	int		i;

	i = 0;
	mem = (char*)malloc(size + 1);
	if (mem)
	{
		while (size + 1 - i > 0)
		{
			mem[i] = '\0';
			i++;
		}
	}
	return (mem);
}
