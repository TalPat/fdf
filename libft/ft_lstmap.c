/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:03:49 by tpatter           #+#    #+#             */
/*   Updated: 2018/05/28 12:56:37 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*prevlist;
	t_list	*firstlist;

	prevlist = NULL;
	while (lst)
	{
		newlist = f(lst);
		if (prevlist)
			prevlist->next = newlist;
		else
			firstlist = newlist;
		prevlist = newlist;
		lst = lst->next;
	}
	return (firstlist);
}
