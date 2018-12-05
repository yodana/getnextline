/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:29:26 by yodana            #+#    #+#             */
/*   Updated: 2018/11/26 15:33:09 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(s1);
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
