/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:41:08 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/22 13:58:25 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*cur_elem;

	new_lst = NULL;
	cur_elem = NULL;
	if (f != NULL)
		while (lst != NULL)
		{
			if (cur_elem == NULL)
			{
				cur_elem = f(lst);
				new_lst = cur_elem;
			}
			else
			{
				cur_elem->next = f(lst);
				cur_elem = cur_elem->next;
			}
			if (cur_elem == NULL)
				return (NULL);
			else
				cur_elem->next = NULL;
			lst = lst->next;
		}
	return (new_lst);
}
