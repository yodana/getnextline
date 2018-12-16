/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2018/12/16 18:22:18 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_save(char **save, char *tmp, char **line)
{
	int i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	*line = ft_strsub(tmp,0,i);
	line++;
	*save = ft_strdup(&tmp[i + 1]);
	ft_strdel(&tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	char buf[BUFF_SIZE + 1];
	int ret;
	char *tmp;

	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	tmp = ft_strnew(0);
	if (save == NULL || !save)
		save = ft_strnew(0);
	else
	{
		tmp = ft_strdup(save);
		ft_strdel(&save);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
	//	printf("buf : %s\n",buf);
		tmp = ft_strjoin((const char*)tmp,(const char*)buf);
//		printf("tmp : %s\n",tmp);
		if (ft_strchr(tmp,'\n'))
		{
			ft_save(&save,tmp,line);
			return (1);
		}
	}
	//printf("tmp : %s\n",tmp);
	if (ret < 0)
		return (-1);
	if (ft_strlen(tmp))
	{
		ft_save(&save, tmp, line);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}
