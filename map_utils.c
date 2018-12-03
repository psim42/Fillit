/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:09:54 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/03 14:08:57 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

void	free_map_content(t_map *map)
{
	int		idx;

	if (map != NULL)
	{
		if (map->tab != NULL)
		{
			idx = 0;
			while (idx < map->size && (map->tab)[idx] != NULL)
			{
				ft_memdel((void**)(map->tab + idx));
				++idx;
			}
			ft_memdel((void**)(&(map->tab)));
		}
		map->size = 0;
	}
}

int		resize_map(t_map *map, int new_size)
{
	int		idx;

	if (map != NULL)
	{
		if (map->tab != NULL)
			free_map_content(map);
		if ((map->tab = (char**)ft_memalloc(sizeof(char*) * new_size)) == NULL)
			return (0);
		idx = 0;
		while (idx < new_size)
		{
			(map->tab)[idx] = (char*)ft_memalloc(sizeof(char) * new_size);
			if ((map->tab)[idx] == NULL)
			{
				free_map_content(map);
				return (0);
			}
			++idx;
		}
		map->size = new_size;
		return (1);
	}
	return (0);
}
