/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:39:07 by tpatter           #+#    #+#             */
/*   Updated: 2018/08/15 15:24:12 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

typedef struct	s_fdf
{
	char		*mapdir;
	t_list		*maplist;
	char		*line;
}				t_fdf;

void			ft_readmap(t_fdf *fdf);

#endif
