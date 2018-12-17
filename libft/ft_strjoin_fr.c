/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_fr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:22:32 by yodana            #+#    #+#             */
/*   Updated: 2018/12/17 14:26:54 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_fr(char *s1, char *s2)
{
	char *dest;

	if (!(dest = ft_strjoin(s1,s2)))
		return (NULL);
	ft_strdel(&s1);
//	ft_strdel(&s2);
	return (dest);
}
