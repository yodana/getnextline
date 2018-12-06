/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2018/12/06 19:31:23 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char *tmp;
	char buf[BUFF_SIZE + 1];
	int j;
	int ret;

	if (BUFF_SIZE <= 0)
		return (-1);
	*line = (char*)malloc(sizeof(char) * 100);
	while ((ret = read(fd, buf, 3)))
	{
		buf[ret] = '\0';
		printf("buf : %s\n",buf);
		//if (ft_strchr(buf, '\n'))
		//{
		//	line++;
	//		ft_strcpy(tmp,buf);
		//	return (0);
		//}
		*line = ft_strjoin((const char*)line,(const char*)buf);
	}
//	printf("%s",line[i]);
//	if (ret == 0)
//		return (0);
	//line++;
	//*line = NULL;
	return (1);
}
