/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:27:11 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/09 12:59:53 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	int		dst_size;

	index = 0;
	dst_size = 0;
	while (index < size && dst[index] != '\0')
	{
		++index;
		++dst_size;
	}
	if (index == size)
	{
		return (size + ft_strlen(src));
	}
	while (index < size - 1 && src[index - dst_size] != '\0')
	{
		dst[index] = src[index - dst_size];
		++index;
	}
	dst[index] = '\0';
	return (dst_size + ft_strlen(src));
}
