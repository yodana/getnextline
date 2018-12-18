/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2018/12/18 17:45:32 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char		*ft_save(char *save,char **line)
{
	int i;
	char *tmp;

	tmp = ft_strdup(save);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	*line = ft_strsub(tmp,0,i);
	line++;
	ft_strdel(&save);
	save = ft_strdup(&tmp[i + 1]);
	ft_strdel(&tmp);
	return (save);
}

int		get_next_line(const int fd, char **line)
{
	static t_list *save = NULL;
	char buf[BUFF_SIZE + 1];
	int ret;
	char *tmp;

	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (save == NULL)
	{
		save = ft_lstnew(NULL, 0);
		save->content = ft_strnew(0);
		save->content_size = fd;
	}
	else if (fd != save->content_size)
	{
		save = save->next;
		save->content = ft_strnew(0);
		save->content_size = fd;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = save->content;
		save->content = ft_strjoin((const char*)save->content ,buf);
		ft_strdel(&tmp);
		if (ft_strchr(buf,'\n'))
		{
			save->content = ft_save(save->content,line);
			return (1);
		}
	}
	if (ret < 0)
		return (-1);
	if (ft_strlen(save->content))
	{
		save->content = ft_save(save->content, line);
		return (1);
	}
	return (0);
}
