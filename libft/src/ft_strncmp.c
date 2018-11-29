/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:46:37 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 15:18:49 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
	{
		return (0);
	}
	idx = 0;
	while (idx < (n - 1) && s1[idx] == s2[idx]
			&& s1[idx] != '\0' && s2[idx] != '\0')
	{
		++idx;
	}
	return ((unsigned char)(s1[idx]) - (unsigned char)(s2[idx]));
}
