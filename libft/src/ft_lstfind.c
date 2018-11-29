/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:19:51 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/21 09:26:12 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstfind(t_list *lst, t_list *val_elem,
		int (*cmp)(t_list *, t_list *))
{
	if (val_elem == NULL || cmp == NULL)
	{
		return (NULL);
	}
	while (lst != NULL)
	{
		if (cmp(lst, val_elem) == 0)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}
