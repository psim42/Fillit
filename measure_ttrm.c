/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_ttrm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:55:46 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/04 12:07:24 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Retourne la taille de l'espace entre le bas du tetrominos et
** le bord du tableau qui le contient.
*/

static int		get_ttrm_bot_offset(t_ttrm *ttrm)
{
	int		bot_off;
	int		idx;

	bot_off = 0;
	while (bot_off < 4)
	{
		idx = 0;
		while (idx < 4)
		{
			if (ttrm->tab[3 - bot_off][idx] != '.')
			{
				return (bot_off);
			}
			++idx;
		}
		++bot_off;
	}
	return (bot_off);
}

/*
** Retourne la taille de l'espace entre la droite du tetrominos et
** le bord du tableau qui le contient.
*/

static int		get_ttrm_right_offset(t_ttrm *ttrm)
{
	int		right_off;
	int		idx;

	right_off = 0;
	while (right_off < 4)
	{
		idx = 0;
		while (idx < 4)
		{
			if (ttrm->tab[idx][3 - right_off] != '.')
			{
				return (right_off);
			}
			++idx;
		}
		++right_off;
	}
	return (right_off);
}

void			measure_ttrm(t_ttrm *ttrm)
{
	if (ttrm != NULL)
	{
		ttrm->width = 4 - get_ttrm_right_offset(ttrm);
		ttrm->height = 4 - get_ttrm_bot_offset(ttrm);
	}
}
