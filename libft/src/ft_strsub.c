/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:02:56 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/21 15:32:29 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	s_size;

	if (len == 0)
	{
		return (ft_strnew(0));
	}
	if (s != NULL)
	{
		s_size = ft_strlen(s);
		if (s_size >= (start + len))
		{
			new_s = ft_strnew(len);
			if (new_s != NULL)
			{
				ft_strncpy(new_s, s + start, len);
				return (new_s);
			}
		}
	}
	return (NULL);
}
