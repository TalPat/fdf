/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:38:40 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/09 16:43:38 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

void	ft_printsingle(t_lem *lem, t_print *print)
{
	if (print->k + print->i <= lem->antno)
	{
		ft_putchar('L');
		ft_putnbr(print->k + print->i);
		ft_putchar('-');
		ft_putstr(lem->path[print->pathno - 1 - print->i - print->l]);
		ft_putchar(' ');
	}
	print->i++;
}

void	ft_printcom(t_lem *lem)
{
	t_print	*print;

	print = (t_print*)malloc(sizeof(t_print));
	print->pathno = 0;
	while (lem->path[print->pathno])
		print->pathno++;
	print->j = 1;
	print->k = 1;
	print->l = print->pathno - 2;
	while (print->j < (print->pathno + lem->antno))
	{
		if (print->j >= print->pathno)
			print->k++;
		print->i = 0;
		ft_putchar('\n');
		while (print->i < print->j && print->i < (print->pathno - 1))
			ft_printsingle(lem, print);
		if (print->l)
			print->l--;
		print->j++;
	}
}
