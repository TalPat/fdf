/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:27:33 by tpatter           #+#    #+#             */
/*   Updated: 2018/06/28 14:33:35 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

static void	ft_scan(int fd, t_fd *myfd, int nochar, char *oldbuff)
{
	t_list	*mystr;
	char	buff[BUFF_SIZE + 1];
	int		rd;
	char	*str;

	oldbuff[nochar] = '\0';
	mystr = ft_lstnew(oldbuff, BUFF_SIZE + 1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		nochar += rd;
		buff[rd] = '\0';
		ft_lstaddend(mystr, buff, BUFF_SIZE + 1);
	}
	str = ft_strnew(nochar + 1);
	while (mystr)
	{
		ft_strcat(str, (char*)mystr->content);
		mystr = ft_lstdestroy(mystr);
	}
	if (str[nochar - 1] == '\n')
		str[nochar - 1] = '\0';
	myfd->str = str;
	myfd->totline = ft_countchr(str, '\n') + 1;
}

static char	*ft_getline(t_fd *myfd)
{
	int		i;
	int		j;
	int		pos;
	int		counter;

	i = 0;
	pos = 0;
	counter = 1;
	j = 0;
	while (counter < myfd->line)
	{
		if ((myfd->str)[i] == '\n')
			counter++;
		i++;
	}
	while (pos < myfd->line)
	{
		if ((myfd->str)[j] == '\n' || (myfd->str)[j] == '\0')
			pos++;
		j++;
	}
	return (ft_strsub(myfd->str, i, j - i - 1));
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static t_fd	*myfd;
	int			nochar;

	if (fd < 0 || !line || (read(fd, buff, 0) <= -1))
		return (-1);
	if ((nochar = read(fd, buff, BUFF_SIZE)) > 0)
	{
		myfd = (t_fd*)malloc(sizeof(t_fd));
		myfd->line = 0;
		ft_scan(fd, myfd, nochar, buff);
	}
	if (!myfd || myfd->line >= myfd->totline)
	{
		*line = ft_strnew(0);
		return (0);
	}
	myfd->line++;
	*line = ft_getline(myfd);
	return (1);
}
