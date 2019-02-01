/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2019/02/01 17:56:04 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list		*ft_lstcheck(t_list **save, int fd)
{
	t_list *tmp;

	tmp = *save;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(save, tmp);
	return (tmp);
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
	static	t_list	*save;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	t_list			*current;

	current = ft_lstcheck(&save, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && BUFF_SIZE > 0 && fd >= 0)
	{
		buf[ret] = '\0';
		current->content = ft_strjoin_fr(current->content, buf, 1);
		if (ft_strchr(buf, '\n'))
		{
			current->content = ft_save(current->content, line);
			return (1);
		}
	}
	if (ret < 0 || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (ft_strlen(current->content))
	{
		current->content = ft_save(current->content, line);
		return (1);
	}
	return (0);
}
