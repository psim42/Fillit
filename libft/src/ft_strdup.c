/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:08:45 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/07 17:39:31 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	int		s1_size;
	int		s1_index;

	s1_size = ft_strlen(s1);
	s1_index = 0;
	s1_cpy = (char *)ft_memalloc(sizeof(*s1) * (s1_size + 1));
	if (s1_cpy == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s1_cpy, s1, s1_size + 1);
	return (s1_cpy);
}
