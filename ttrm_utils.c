/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttrm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:49:48 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/03 15:32:21 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fillit.h"

/*
** Retourne la taille de l'espace entre le haut du tetrominos et
** le bord du tableau qui le contient.
*/

static int		get_ttrm_top_offset(t_ttrm *ttrm)
{
	int		top_off;
	int		idx;

	top_off = 0;
	while (top_off < 4)
	{
		idx = 0;
		while (idx < 4)
		{
			if (ttrm->tab[top_off][idx] == '#')
			{
				return (top_off);
			}
			++idx;
		}
		++top_off;
	}
	return (top_off);
}

/*
** Retourne la taille de l'espace entre la gauche du tetrominos et
** le bord du tableau qui le contient.
*/

static int		get_ttrm_left_offset(t_ttrm *ttrm)
{
	int		left_off;
	int		idx;

	left_off = 0;
	while (left_off < 4)
	{
		idx = 0;
		while (idx < 4)
		{
			if (ttrm->tab[idx][left_off] == '#')
			{
				return (left_off);
			}
			++idx;
		}
		++left_off;
	}
	return (left_off);
}

void			normalize_ttrm(t_ttrm *ttrm)
{
	int		top_off;
	int		left_off;
	int		x_ind;
	int		y_ind;

	top_off = get_ttrm_top_offset(ttrm);
	left_off = get_ttrm_left_offset(ttrm);
	y_ind = 0;
	while (y_ind < 4)
	{
		x_ind = 0;
		while (x_ind < 4)
		{
			if ((x_ind + left_off) < 4 && (y_ind + top_off) < 4)
			{
				ttrm->tab[y_ind][x_ind] =
					ttrm->tab[y_ind + top_off][x_ind + left_off];
			}
			else
				ttrm->tab[y_ind][x_ind] = '.';
			++x_ind;
		}
		++y_ind;
	}
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
