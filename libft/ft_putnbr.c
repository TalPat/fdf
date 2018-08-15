/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:01:04 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/28 14:16:11 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void			ft_putnbr(int n)
{
	int	i;
	int	digits;

	i = 0;
	digits = ft_nodigits(n);
	if (n == 0)
		ft_putchar('0');
	else
	{
		if (n < 0)
			ft_putchar('-');
		while (i < digits)
		{
			if (n < 0)
				ft_putchar((n / ft_tenpower(digits - 1 - i)) * -1 + '0');
			else
				ft_putchar(n / ft_tenpower(digits - 1 - i) + '0');
			n = n - ((n / ft_tenpower(digits - 1 - i)) *
					ft_tenpower(digits - 1 - i));
			i++;
		}
	}
}
