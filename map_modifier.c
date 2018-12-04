/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:28:59 by psim              #+#    #+#             */
/*   Updated: 2018/12/04 13:44:55 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void		abort_ttrm(t_map *map, t_ttrm *ttrm, t_coord cd, int i)
{
	int tx;
	int ty;

	if (i == 0)
		return ;
	ty = 0;
	while (ty < ttrm->height)
	{
		tx = 0;
		while (tx < ttrm->width)
		{
			if (ttrm->tab[ty][tx] != '.' && map->tab[cd.y + ty][cd.x + tx]
					!= '.')
			{
				map->tab[cd.y + ty][cd.x + tx] = '.';
			}
			tx++;
			i--;
			if (i == 0)
				return ;
		}
		ty++;
	}
}

t_coord		coord_struct(int x, int y)
{
	t_coord cd;

	cd.x = x;
	cd.y = y;
	return (cd);
}

void		remove_ttrm(t_map *map, t_ttrm *ttrm, int x, int y)
{
	abort_ttrm(map, ttrm, coord_struct(x, y), 16);
}

int			insert_ttrm(t_map *map, t_ttrm *ttrm, int x, int y)
{
	int tx;
	int ty;
	int i;

	ty = -1;
	i = 0;
	while (++ty < ttrm->height)
	{
		tx = -1;
		while (++tx < ttrm->width)
		{
			if (ttrm->tab[ty][tx] != '.')
			{
				if (map->tab[y + ty][x + tx] == '.')
					map->tab[y + ty][x + tx] = ttrm->tab[ty][tx];
				else
				{
					abort_ttrm(map, ttrm, coord_struct(x, y), i);
					return (0);
				}
			}
			i++;
		}
	}
	return (1);
}
