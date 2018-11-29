/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttrm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:49:48 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/29 17:00:59 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void			free_ttrm_tab(t_ttrm **ttrm)
{
	int		idx;

	if (ttrm != NULL)
	{
		idx = 0;
		while (ttrm[idx] != NULL)
		{
			ft_memdel((void**)(ttrm + idx));
			++idx;
		}
		ft_memdel((void**)(&ttrm));
	}
}
