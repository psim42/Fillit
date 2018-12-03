/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emplace_ttrm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:13:37 by psim              #+#    #+#             */
/*   Updated: 2018/12/03 12:16:02 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		emplace_ttrm(t_map *map, t_ttrm *ttrm, int x, int y)
{
	int tx;
	int ty;

	tx = 0;
	ty = 0;
	while (ttrm->tab[ty] < 4)
	{
		while (ttrm->tab[tx] < 4)
		{
			if (map->tab[x] == '.')
				map->tab[x] = ttrm->tab[tx];
			if (tx >= map->size && ttrm->tab[tx] != '.')
			{
				remove_ttrm(/* */);
				return (0);
			}

