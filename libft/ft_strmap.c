/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:17:33 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/28 16:55:54 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	temp = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	if (temp)
	{
		while (s[i])
		{
			temp[i] = f(s[i]);
			i++;
		}
	}
	return (temp);
}
