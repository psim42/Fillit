/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:40:47 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/04 12:03:30 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

/*
** Retourne la taille minimum possible pour les tetrominos donnes.
*/

static int		get_min_fillit_square(t_ttrm **tab)
{
	int		size;
	int		idx;

	size = 0;
	if (tab != NULL)
	{
		idx = 0;
		while (tab[idx] != NULL)
		{
			size += 4;
			++idx;
		}
	}
	return (ft_sqrtru(size));
}

/*
** Resous fillit avec la map de taille fixe et les tetrominos passes en
** parametre.
** Retourne 1 si une solution a ete trouvee (elle sera contenue dans map)
** ou 0 s'il n'y a pas de solution.
*/

static int		try_fillit_map(t_map *map, t_ttrm **ttrm_tab)
{
	int		x;
	int		y;

	if (map == NULL || ttrm_tab == NULL)
		return (0);
	if (*ttrm_tab == NULL)
		return (1);
	y = 0;
	while (y <= (map->size - (*ttrm_tab)->height))
	{
		x = 0;
		while (x <= (map->size - (*ttrm_tab)->width))
		{
			if (insert_ttrm(map, *ttrm_tab, x, y) == 1)
			{
				if (try_fillit_map(map, ttrm_tab + 1) == 1)
					return (1);
				else
					remove_ttrm(map, *ttrm_tab, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

t_map			*resolve_fillit(t_ttrm **ttrm_tab)
{
	int		cur_map_size;
	t_map	*map;

	cur_map_size = get_min_fillit_square(ttrm_tab);
	if ((map = (t_map*)ft_memalloc(sizeof(*map))) == NULL)
		return (NULL);
	if (resize_map(map, cur_map_size) == 0)
	{
		ft_memdel((void**)(&map));
		return (NULL);
	}
	while (try_fillit_map(map, ttrm_tab) == 0)
	{
		++cur_map_size;
		if (resize_map(map, cur_map_size) == 0)
		{
			ft_memdel((void**)(&map));
			return (NULL);
		}
	}
	return (map);
}
