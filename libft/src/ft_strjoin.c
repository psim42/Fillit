/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:13:12 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 16:16:30 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	char	*new_str;

	if (s1 != NULL && s2 != NULL)
	{
		s1_size = ft_strlen(s1);
		s2_size = ft_strlen(s2);
		new_str = ft_strnew(s1_size + s2_size);
		if (new_str != NULL)
		{
			ft_strcpy(new_str, s1);
			ft_strcpy(new_str + s1_size, s2);
			return (new_str);
		}
	}
	return (NULL);
}
