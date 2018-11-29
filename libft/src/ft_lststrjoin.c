/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:06:53 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/24 16:16:53 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_lststrjoin(t_list *lst)
{
	char	*new_str;
	size_t	str_size;
	size_t	index;
	t_list	*cur_elem;

	cur_elem = lst;
	str_size = 0;
	while (cur_elem != NULL)
	{
		str_size += cur_elem->content_size;
		cur_elem = cur_elem->next;
	}
	new_str = ft_strnew(str_size);
	if (new_str == NULL)
		return (NULL);
	index = 0;
	cur_elem = lst;
	while (cur_elem != NULL)
	{
		ft_memcpy(new_str + index, (char*)(cur_elem->content),
				cur_elem->content_size);
		index += cur_elem->content_size;
		cur_elem = cur_elem->next;
	}
	return (new_str);
}
