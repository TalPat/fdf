/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdestroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 21:00:49 by tpatter           #+#    #+#             */
/*   Updated: 2018/06/06 21:05:32 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstdestroy(t_list *lst)
{
	t_list	*tmp;

	free(lst->content);
	tmp = lst->next;
	free(lst);
	return (tmp);
}
