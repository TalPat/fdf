/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:31:04 by tpatter           #+#    #+#             */
/*   Updated: 2018/06/06 15:58:57 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;
	void	*copy;

	if ((fresh = (t_list*)malloc(sizeof(t_list))))
	{
		if (content)
		{
			copy = malloc(content_size);
			ft_memcpy(copy, content, content_size);
			fresh->content = copy;
			fresh->content_size = content_size;
		}
		else
		{
			fresh->content = NULL;
			fresh->content_size = 0;
		}
		fresh->next = NULL;
	}
	return (fresh);
}
