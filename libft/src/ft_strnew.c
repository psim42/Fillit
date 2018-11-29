/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:30:55 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/15 10:21:51 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	size_to_use;

	size_to_use = size + 1;
	if (size_to_use > size)
	{
		return ((char*)ft_memalloc(size_to_use));
	}
	else
	{
		return ((char*)NULL);
	}
}
