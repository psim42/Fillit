/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:23:21 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/21 09:33:35 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstaddafter(t_list *lst, t_list *new_elem)
{
	if (lst != NULL && new_elem != NULL)
	{
		new_elem->next = lst->next;
		lst->next = new_elem;
	}
}
