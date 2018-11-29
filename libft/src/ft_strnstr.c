/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:26:36 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 13:08:06 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	find_idx;

	if (*needle == '\0')
	{
		return ((char*)(haystack));
	}
	idx = 0;
	while (idx < len && haystack[idx] != '\0')
	{
		find_idx = 0;
		while ((idx + find_idx) < len
				&& haystack[idx + find_idx] == needle[find_idx]
				&& haystack[idx + find_idx] != '\0' && needle[find_idx] != '\0')
		{
			++find_idx;
		}
		if (needle[find_idx] == '\0')
		{
			return ((char*)(haystack + idx));
		}
		++idx;
	}
	return (0);
}
