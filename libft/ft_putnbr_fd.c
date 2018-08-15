/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:21:52 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/28 14:20:27 by tpatter          ###   ########.fr       */
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

void			ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	digits;

	i = 0;
	digits = ft_nodigits(n);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		while (i < digits)
		{
			if (n < 0)
				ft_putchar_fd((n / ft_tenpower(digits - 1 - i)) * -1 + '0', fd);
			else
				ft_putchar_fd(n / ft_tenpower(digits - 1 - i) + '0', fd);
			n = n - ((n / ft_tenpower(digits - 1 - i)) *
					ft_tenpower(digits - 1 - i));
			i++;
		}
	}
}
