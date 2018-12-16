/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2018/12/16 20:34:31 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
void		ft_save(char **save,char **line)
{
	int i;
	char *tmp;

	tmp = ft_strdup(*save);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	*line = ft_strsub(tmp,0,i);
	line++;
	ft_strdel(save);
	*save = ft_strdup(&tmp[i + 1]);
	ft_strdel(&tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	char buf[BUFF_SIZE + 1];
	int ret;

	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (save == NULL)
		save = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		save = ft_strjoin((const char*)save,(const char*)buf);
		if (ft_strchr(buf,'\n'))
		{
			ft_save(&save,line);
			return (1);
		}
	}
	if (ret < 0)
		return (-1);
	if (ft_strlen(save))
	{
		ft_save(&save, line);
		return (1);
	}
	ft_strdel(&save);
	return (0);
}
