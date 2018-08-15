/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:03:08 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/30 11:37:01 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tracker;
	t_list	*nxtptr;

	tracker = *alst;
	while (tracker)
	{
		nxtptr = tracker->next;
		del(tracker->content, tracker->content_size);
		free(tracker);
		tracker = nxtptr;
	}
	*alst = NULL;
}
