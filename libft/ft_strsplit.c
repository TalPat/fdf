/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:20:59 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/25 17:29:55 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nowords(char const *s, char c)
{
	int	i;
	int	nowords;

	if (!s[0])
		return (0);
	i = 1;
	nowords = 0;
	if (s[0] != c)
		nowords++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			nowords++;
		i++;
	}
	return (nowords);
}

static int	*ft_wrdstrt(char const *s, char c)
{
	int	*iarr;
	int	i;
	int	strtadd;

	iarr = (int*)malloc(sizeof(int) * ft_nowords(s, c));
	if (!s[0])
		return (iarr);
	i = 1;
	strtadd = 0;
	if (s[0] != c)
		iarr[strtadd++] = 0;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			iarr[strtadd++] = i;
		i++;
	}
	return (iarr);
}

static int	ft_wrdlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_strsplit2(char const *s, char c, int i, int j)
{
	char	**fresh;
	int		*iarr;

	iarr = ft_wrdstrt(s, c);
	if ((fresh = (char**)malloc(sizeof(char*) * (ft_nowords(s, c) + 1))))
	{
		while (i < ft_nowords(s, c))
		{
			fresh[i] = (char*)malloc(ft_wrdlen(s + iarr[i], c) + 1);
			if (fresh[i])
			{
				j = 0;
				while (j < ft_wrdlen(s + iarr[i], c))
				{
					fresh[i][j] = s[iarr[i] + j];
					j++;
				}
				fresh[i][j] = '\0';
			}
			i++;
		}
		fresh[i] = NULL;
	}
	free(iarr);
	return (fresh);
}

char		**ft_strsplit(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s)
		return (ft_strsplit2(s, c, i, j));
	else
		return (NULL);
}
