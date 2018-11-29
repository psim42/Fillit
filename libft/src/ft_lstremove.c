/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:39:35 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/22 14:49:42 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void		lstremove_not_head(t_list *lst, t_list *ptr_elem,
		void (*del)(void *, size_t))
{
	t_list *old_lst;

	old_lst = lst;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst == ptr_elem)
		{
			lst = lst->next;
			old_lst->next = lst;
			ft_lstdelone(&ptr_elem, del);
			return ;
		}
		else
		{
			old_lst = lst;
			lst = lst->next;
		}
	}
}

void			ft_lstremove(t_list **lst, t_list *ptr_elem,
		void (*del)(void *, size_t))
{
	if (lst != NULL && ptr_elem != NULL)
	{
		if (*lst == ptr_elem)
		{
			*lst = (*lst)->next;
			ft_lstdelone(&ptr_elem, del);
		}
		else
		{
			lstremove_not_head(*lst, ptr_elem, del);
		}
	}
}
