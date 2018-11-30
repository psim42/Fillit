/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttrm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:49:48 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/30 09:10:29 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void			free_ttrm_tab(t_ttrm **ttrm_tab)
{
	int		idx;

	if (ttrm_tab != NULL)
	{
		idx = 0;
		while (ttrm_tab[idx] != NULL)
		{
			ft_memdel((void**)(ttrm_tab + idx));
			++idx;
		}
		ft_memdel((void**)(&ttrm_tab));
	}
}
