/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:58:25 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/19 11:29:00 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_elem;

	new_elem = (t_list*)ft_memalloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_elem->content_size = 0;
		new_elem->content = NULL;
	}
	else
	{
		new_elem->content_size = content_size;
		new_elem->content = ft_memalloc(content_size);
		if (new_elem->content == NULL)
		{
			ft_memdel((void**)&new_elem);
			return (NULL);
		}
		ft_memcpy(new_elem->content, content, content_size);
	}
	new_elem->next = NULL;
	return (new_elem);
}
