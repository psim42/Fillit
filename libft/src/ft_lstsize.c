/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:40:26 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/21 09:42:29 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	lst_size;

	lst_size = 0;
	while (lst != NULL)
	{
		++lst_size;
		lst = lst->next;
	}
	return (lst_size);
}
