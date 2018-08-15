/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:37:37 by tpatter           #+#    #+#             */
/*   Updated: 2018/06/06 16:22:11 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstaddend(t_list *lst, void *content, size_t content_size)
{
	t_list	*last;

	while (lst->next)
		lst = lst->next;
	if ((last = (t_list*)malloc(sizeof(t_list))))
	{
		if (content)
		{
			last->content = malloc(content_size);
			ft_memcpy(last->content, content, content_size);
			last->content_size = content_size;
		}
		else
		{
			last->content = NULL;
			last->content_size = 0;
		}
		last->next = NULL;
		lst->next = last;
	}
}
