/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:46:50 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 12:31:36 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		index_find;

	index = 0;
	index_find = -1;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
		{
			index_find = index;
		}
		++index;
	}
	if (c == '\0')
	{
		return ((char*)(s + index));
	}
	else if (index_find != -1)
	{
		return ((char*)(s + index_find));
	}
	else
	{
		return (NULL);
	}
}
