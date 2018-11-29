/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:12:19 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/15 12:17:29 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	is_space_char(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	count_ending_space(char const *s)
{
	int		end_sp_count;
	int		index;

	end_sp_count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (is_space_char(s[index]) == 1)
		{
			++end_sp_count;
		}
		else
		{
			end_sp_count = 0;
		}
		++index;
	}
	return (end_sp_count);
}

char		*ft_strtrim(char const *s)
{
	int		s_len_aftr_sp;
	int		end_sp_count;
	char	*new_s;

	if (s == NULL)
	{
		return (NULL);
	}
	while (*s != '\0' && is_space_char(*s))
	{
		++s;
	}
	if (*s == '\0')
	{
		return (ft_strnew(0));
	}
	s_len_aftr_sp = ft_strlen(s);
	end_sp_count = count_ending_space(s);
	new_s = ft_strnew(s_len_aftr_sp - end_sp_count);
	if (new_s == NULL)
	{
		return (NULL);
	}
	ft_strncpy(new_s, s, s_len_aftr_sp - end_sp_count);
	return (new_s);
}
