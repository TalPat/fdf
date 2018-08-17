/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildperslist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:04:55 by talon             #+#    #+#             */
/*   Updated: 2018/08/17 21:29:06 by talon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include "mlx.h"

void	ft_buildperslist(t_fdf *fdf)
{
	t_list	*tmp;
	t_vect	*persvect;

	tmp = fdf->vectlist;
	fdf->perslist = ft_lstnew(tmp->content, sizeof(t_vect));
	tmp = tmp->next;
	while (tmp)
	{
		ft_lstaddend(fdf->perslist, tmp->content, sizeof(t_vect));
		tmp = tmp->next;
	}
}
