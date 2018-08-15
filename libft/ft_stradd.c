/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:31:50 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/09 13:41:27 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_stradd(char *str, char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	arr[i] = ft_strdup(str);
	arr[i + 1] = NULL;
}
