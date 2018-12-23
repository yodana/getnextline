/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2018/12/23 18:11:57 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list		*ft_lstb(t_list *save, int fd)
{
	save = ft_lstnew(NULL, 0);
	save->content = ft_strnew(0);
	save->content_size = fd;
	return (save);
}

char		*ft_save(char *save, char **line)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(save);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	*line = ft_strsub(tmp, 0, i);
	line++;
	ft_strdel(&save);
	save = ft_strdup(&tmp[i + 1]);
	ft_strdel(&tmp);
	return (save);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*save = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	
	if (save == NULL)
	{
		save = ft_lstb(save, fd);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && BUFF_SIZE > 0 && fd >= 0)
	{
		buf[ret] = '\0';
		save->content = ft_strjoin_fr(save->content, buf, 1);
	//	printf("nbr de lst = %d\n",ft_lstcount(save));
	//	printf("save de %d = %s\n", (int)save->content_size, save->content);
		if (ft_strchr(buf, '\n'))
		{
			save->content = ft_save(save->content, line);
			return (1);
		}
	}
	if (ret < 0 || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (ft_strlen(save->content))
	{
		save->content = ft_save(save->content, line);
		return (1);
	}
	return (0);
}
