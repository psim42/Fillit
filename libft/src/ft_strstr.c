/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:25:20 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 11:38:02 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		idx;
	int		find_idx;

	if (*needle == '\0')
	{
		return ((char*)(haystack));
	}
	idx = 0;
	while (haystack[idx] != '\0')
	{
		find_idx = 0;
		while (haystack[idx + find_idx] == needle[find_idx]
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
