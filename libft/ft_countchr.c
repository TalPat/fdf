/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:02:40 by tpatter           #+#    #+#             */
/*   Updated: 2018/06/06 17:12:07 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchr(char *str, char c)
{
	int	i;
	int	nochar;

	i = 0;
	nochar = 0;
	while (str[i])
	{
		if (str[i] == c)
			nochar++;
		i++;
	}
	return (nochar);
}
