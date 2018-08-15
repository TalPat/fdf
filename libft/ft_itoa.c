/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:25:22 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/30 11:35:06 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_tenpower(int exp)
{
	if (exp == 0)
		return (1);
	return (10 * ft_tenpower(exp - 1));
}

static int		ft_nodigits(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_isneg(long n, char *fresh, int digits)
{
	int	i;

	i = 1;
	fresh = (char*)malloc(sizeof(char) * (digits + 2));
	if (fresh)
	{
		fresh[0] = '-';
		n = n * -1;
		while (i <= digits)
		{
			fresh[i] = n / ft_tenpower(digits - i) + '0';
			n = n - ((n / ft_tenpower(digits - i)) * ft_tenpower(digits - i));
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}

static char		*ft_ispos(int n, char *fresh, int digits)
{
	int	i;

	i = 0;
	fresh = (char*)malloc(sizeof(char) * (digits + 1));
	if (fresh)
	{
		while (i < digits)
		{
			fresh[i] = n / ft_tenpower(digits - 1 - i) + '0';
			n = n - ((n / ft_tenpower(digits - 1 - i)) *
					ft_tenpower(digits - 1 - i));
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}

char			*ft_itoa(int n)
{
	int		digits;
	char	*fresh;

	fresh = NULL;
	if (n == 0)
	{
		fresh = (char*)malloc(sizeof(char) * 2);
		if (fresh)
			ft_strcpy(fresh, "0");
	}
	digits = ft_nodigits(n);
	if (n > 0)
		return (ft_ispos(n, fresh, digits));
	if (n < 0)
		return (ft_isneg(n, fresh, digits));
	return (fresh);
}
