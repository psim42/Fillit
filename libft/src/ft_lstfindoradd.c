/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindoradd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:02:27 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/23 15:11:29 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstfindoradd(t_list **lst, t_list *val_elem,
		int (*cmp)(t_list *, t_list *))
{
	t_list	*find_res;

	if (lst != NULL && val_elem != NULL)
	{
		find_res = ft_lstfind(*lst, val_elem, cmp);
		if (find_res == NULL)
		{
			ft_lstadd(lst, val_elem);
			return (val_elem);
		}
		else
		{
			return (find_res);
		}
	}
	return (NULL);
}
