/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:04:56 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/08 15:52:46 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		s1_size;

	index = 0;
	s1_size = ft_strlen(s1);
	while (index < n && s2[index] != '\0')
	{
		s1[s1_size + index] = s2[index];
		++index;
	}
	s1[s1_size + index] = '\0';
	return (s1);
}
