/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:07:34 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/27 09:31:00 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

void	ft_readmap(t_fdf *fdf)
{
	int		fd;

	fd = open(fdf->mapdir, O_RDONLY);
	if (ft_grabline(fd, &(fdf->line)) == 1)
		fdf->maplist = ft_lstnew(fdf->line, ft_strlen(fdf->line) + 1);
	else
		fdf->maplist = NULL;
	free(fdf->line);
	while (ft_grabline(fd, &(fdf->line)) == 1)
	{
		ft_lstaddend(fdf->maplist, fdf->line, ft_strlen(fdf->line) + 1);
		free(fdf->line);
	}
	if (!fdf->maplist)
		fdf->error = 2;
}
