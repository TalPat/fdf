/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:38:00 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/28 15:23:03 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_trimblanks(const char *str)
{
	int	i;
	int	checker;

	i = 0;
	checker = 0;
	while (str[i] && (str[i] <= '0' || str[i] >= '9'))
	{
		if (str[i] == '+' || str[i] == '-')
			checker++;
		i++;
	}
	if (checker >= 2)
		return (str);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\n' || str[i] == '+')
	{
		i++;
	}
	return (str + i);
}

int					ft_atoi(const char *str)
{
	int			val;
	int			i;
	int			sign;
	const char	*newstr;

	newstr = ft_trimblanks(str);
	val = 0;
	i = 0;
	sign = 1;
	if (newstr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (newstr[i])
	{
		if (newstr[i] >= '0' && newstr[i] <= '9')
		{
			val = val * 10;
			val += newstr[i++] - '0';
		}
		else
			return (val * sign);
	}
	return (val * sign);
}
