/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:48:22 by psim              #+#    #+#             */
/*   Updated: 2018/12/03 14:12:42 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	print_map(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->size)
	{
		while (x < map->size)
		{
			ft_putchar(map->tab[y][x]);
			ft_putchar('\n');
			x++;
		}
		y++;
	}
}
