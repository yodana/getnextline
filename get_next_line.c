/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:12:52 by yodana            #+#    #+#             */
/*   Updated: 2018/12/05 19:33:37 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		get_next_line(const int fd, char **line)
{
	static int i;
	char buf[BUFF_SIZE + 1];
	int j;

	j = 0;
	i = 0;
	while (read(fd, buf + j, 1) && buf[j] != '\n')
		j++;
//	printf("%s",buf);
	line[i] = (char*)malloc(sizeof(char) * j + 1);
	line[i] = ft_strjoin((const char*)line[i],(const char*)buf);
	printf("%s",line[i]);
	if (read(fd, buf + j, 1) == 0)
		return (0);
		i++;
	return (1);
}
