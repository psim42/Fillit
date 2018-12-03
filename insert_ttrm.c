/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ttrm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:07:03 by psim              #+#    #+#             */
/*   Updated: 2018/12/03 13:50:32 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	abort_ttrm(t_map *map, t_ttrm *ttrm, t_coord cd, int i)
{
	int tx;
	int ty;
	int i;

	while (ty < 4 && i)
	{
		while (tx < 4 && i)
		{
			if (ttrm->tab[ty][tx] != '.' && map->tab[y + ty][x + tx] != '.')
			{
				map->tab[y + ty][x + tx] = '.';
				i--;
			}
			tx++;
		}
		ty++;
	}
}

static void	coord_struct(int x, int y)
{
	t_coord cd;

	cd->x = x;
	cd->y = y;
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
				map->tab[y + ty][x + tx] = ttrm->tab[tx];
				i++;
			}
			else
			{
				abort_ttrm(map, ttr, coord_struct(x, y), i);
				return (0);
			}
			tx++;
		}
		ty++;
	}
	return (1);
}
