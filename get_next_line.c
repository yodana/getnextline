/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2018/12/17 19:32:45 by yodana           ###   ########.fr       */
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
	static t_list *save;
	char buf[BUFF_SIZE + 1];
	int ret;
	char *tmp;

	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	//if (save == NULL)
	//save->content = ft_strnew(0);
//	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
///	{
//		buf[ret] = '\0';
//		tmp = save->content;
		//tmp = ft_strjoin(save->content,"lol");
//		ft_strdel(&tmp);
//		if (ft_strchr(buf,'\n'))
//		{
//			ft_save(save->content,line);
//			return (1);
//		}
//	}
//	if (ret < 0)
//		return (-1);
//	if (ft_strlen(save->content))
//	{
//		ft_save(save->content, line);
//		return (1);
//	}
//	ft_strdel(save->content);*/
	return (0);
}
