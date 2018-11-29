/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstallocnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:13:09 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/23 15:30:56 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstallocnew(size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list*)ft_memalloc(sizeof(*new_elem));
	if (new_elem == NULL)
	{
		return (NULL);
	}
	new_elem->content_size = content_size;
	new_elem->content = ft_memalloc(content_size);
	if (new_elem->content == NULL)
	{
		ft_memdel((void**)(&new_elem));
		return (NULL);
	}
	return (new_elem);
}
