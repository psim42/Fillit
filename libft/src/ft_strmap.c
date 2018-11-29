/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:27:10 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 14:36:33 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	int		s_size;
	char	*new_s;

	if (s != NULL && f != NULL)
	{
		s_size = ft_strlen(s);
		new_s = ft_strnew(s_size);
		if (new_s != NULL)
		{
			index = 0;
			while (s[index] != '\0')
			{
				new_s[index] = (*f)(s[index]);
				++index;
			}
			return (new_s);
		}
	}
	return (NULL);
}
