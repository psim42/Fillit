/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:00:22 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/08 17:16:22 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (dst == src)
	{
		return (dst);
	}
	index = 0;
	if ((char*)dst <= (char*)src + len && src <= dst)
	{
		while (index < len)
		{
			((unsigned char *)dst)[len - index - 1] =
				((unsigned char *)src)[len - index - 1];
			++index;
		}
	}
	else
	{
		while (index < len)
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			++index;
		}
	}
	return (dst);
}
