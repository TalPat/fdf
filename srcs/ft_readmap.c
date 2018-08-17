/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talon <talon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:07:34 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/17 21:00:57 by talon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>

void	ft_readmap(t_fdf *fdf)
{
	int		fd;

	fd = open(fdf->mapdir, O_RDONLY);
	if (ft_grabline(fd, &(fdf->line)) == 1)
		fdf->maplist = ft_lstnew(fdf->line, ft_strlen(fdf->line) + 1);
	else
		fdf->maplist = NULL;
	while (ft_grabline(fd, &(fdf->line)) == 1)
	{
		ft_lstaddend(fdf->maplist, fdf->line, ft_strlen(fdf->line) + 1);
	}
}
