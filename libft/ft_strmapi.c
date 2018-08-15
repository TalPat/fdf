/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:31:29 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/28 16:55:26 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	temp = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	if (temp)
	{
		while (s[i])
		{
			temp[i] = f(i, s[i]);
			i++;
		}
	}
	return (temp);
}
