/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deflstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:54:48 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/24 11:56:57 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_deflstdel(void *content, size_t content_size)
{
	(void)content_size;
	if (content != NULL)
	{
		ft_memdel(&content);
	}
}
