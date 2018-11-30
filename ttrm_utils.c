/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttrm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:49:48 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/30 11:37:47 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fillit.h"

/*
** Colorie le bloc x/y puis les blocs lies au bloc x/y du tetrominos
** passe en parametre puis retourne le nombre de blocs colories.
*/

static int		color_ttrm_block_linked(t_ttrm *ttrm, int x, int y)
{
	int		link_count;

	if (ttrm == NULL || ttrm->tab[y][x] != '#')
		return (0);
	link_count = 1;
	ttrm->tab[y][x] = '@';
	if (x > 0)
		link_count += color_ttrm_block_linked(ttrm, x - 1, y);
	if (y > 0)
		link_count += color_ttrm_block_linked(ttrm, x, y - 1);
	if (x < 3)
		link_count += color_ttrm_block_linked(ttrm, x + 1, y);
	if (y < 3)
		link_count += color_ttrm_block_linked(ttrm, x, y + 1);
	return (link_count);
}

/*
** Remet le bloc x/y puis les blocs lies au bloc x/y d'un tetrominos
** a leur etat avant la coloration.
*/

static void		reverse_color_ttrm_block_linked(t_ttrm *ttrm, int x, int y)
{
	if (ttrm == NULL || ttrm->tab[y][x] != '@')
		return ;
	ttrm->tab[y][x] = '#';
	if (x > 0)
		reverse_color_ttrm_block_linked(ttrm, x - 1, y);
	if (y > 0)
		reverse_color_ttrm_block_linked(ttrm, x, y - 1);
	if (x < 3)
		reverse_color_ttrm_block_linked(ttrm, x + 1, y);
	if (y < 3)
		reverse_color_ttrm_block_linked(ttrm, x, y + 1);
}

/*
** Retourne 1 si le bloc x/y et les blocs lies au bloc x/y du tetrominos
** forment un tetrominos valide (4 bloc au total), retourne 0 sinon.
*/

static int		check_ttrm_block_link_valid(t_ttrm *ttrm, int x, int y)
{
	int		link_count;

	link_count = color_ttrm_block_linked(ttrm, x, y);
	reverse_color_ttrm_block_linked(ttrm, x, y);
	return (link_count == 4 ? 1 : 0);
}

int				check_ttrm_block(t_ttrm *ttrm)
{
	int		x;
	int		y;
	int		bloc_count;

	if (ttrm == NULL)
		return (0);
	bloc_count = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (ttrm->tab[y][x] == '#')
			{
				if (bloc_count == 0)
					if (check_ttrm_block_link_valid(ttrm, x, y) == 0)
						return (0);
				++bloc_count;
			}
			++x;
		}
		++y;
	}
	return (bloc_count == 4 ? 1 : 0);
}

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
