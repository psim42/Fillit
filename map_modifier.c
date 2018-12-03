/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:28:59 by psim              #+#    #+#             */
/*   Updated: 2018/12/03 14:33:50 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	remove_ttrm(t_map *map, t_ttrm *ttrm, int x, int y)
{
	abort_ttrm(map, ttrm, coord_struct(x, y), 16);
}

void	abort_ttrm(t_map *map, t_ttrm *ttrm, t_coord cd, int i)
{
	int tx;
	int ty;

	tx = 0;
	ty = 0;
	while (ty < 4 && i)
	{
		while (tx < 4 && i)
		{
			if (ttrm->tab[ty][tx] != '.' && map->tab[cd.y + ty][cd.x + tx] != '.')
			{
				map->tab[cd.y + ty][cd.x + tx] = '.';
				i--;
			}
			tx++;
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

int			insert_ttrm(t_map *map, t_ttrm *ttrm, int x, int y)
{
	int tx;
	int ty;
	int i;

	tx = 0;
	ty = 0;
	i = 0;
	while (ty < 4)
	{
		while (tx < 4)
		{
			if (ttrm->tab[ty][tx] != '.' && (x + tx >= map->size
						|| y + ty >= map->size))
			{
				abort_ttrm(map, ttrm, coord_struct(x, y), i);
				return (0);
			}
			if (ttrm->tab[ty][tx] != '.' && map->tab[y + ty][x + tx] == '.')
			{
				map->tab[y + ty][x + tx] = ttrm->tab[ty][tx];
				i++;
			}
			else
			{
				abort_ttrm(map, ttrm, coord_struct(x, y), i);
				return (0);
			}
			tx++;
		}
		ty++;
	}
	return (1);
}
