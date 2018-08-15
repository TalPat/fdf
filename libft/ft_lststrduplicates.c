/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrduplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 14:42:01 by tpatter           #+#    #+#             */
/*   Updated: 2018/07/25 17:17:15 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lststrduplicates(t_list *lst)
{
	t_list	*i;
	t_list	*j;
	int		count;

	if (!lst)
		return (0);
	i = lst;
	while (i->next)
	{
		j = lst;
		count = 0;
		while (j)
		{
			if (ft_atoi(j->content) == ft_atoi(i->content))
				count++;
			j = j->next;
		}
		if (count > 1)
			return (1);
		i = i->next;
	}
	return (0);
}
