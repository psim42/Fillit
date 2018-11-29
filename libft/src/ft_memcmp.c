/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:49:15 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/13 17:34:56 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	if (n == 0)
	{
		return (0);
	}
	index = 0;
	while (index < (n - 1)
			&& ((unsigned char*)s1)[index] == ((unsigned char *)s2)[index])
	{
		++index;
	}
	return (((unsigned char*)s1)[index] - ((unsigned char *)s2)[index]);
}
