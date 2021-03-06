/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ttrm_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:49:30 by psim              #+#    #+#             */
/*   Updated: 2018/12/04 13:53:37 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Remplace les blocs du tetrominos par une lettre.
*/

static void		ttrm_bloc_to_letter(t_ttrm *ttrm, char letter)
{
	int		x;
	int		y;

	if (ttrm != NULL)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (ttrm->tab[y][x] != '.')
				{
					ttrm->tab[y][x] = letter;
				}
				++x;
			}
			++y;
		}
	}
}

t_ttrm			**fd_to_ttrm_tab(int fd)
{
	int		ret;
	int		i;
	t_ttrm	**tab;

	tab = (t_ttrm**)ft_memalloc(sizeof(t_ttrm*) * 27);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while ((ret = fill_ttrm(fd, &(tab[i]))) == 1 && i < 26)
	{
		ttrm_bloc_to_letter(tab[i], 'A' + i);
		measure_ttrm(tab[i]);
		i++;
	}
	if (ret == -1 || i == 26)
	{
		free_ttrm_tab(tab);
		return (NULL);
	}
	ttrm_bloc_to_letter(tab[i], 'A' + i);
	measure_ttrm(tab[i]);
	return (tab);
}

static int		check_line(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static int		read_ttrm_lines(int fd, t_ttrm **new_ttrm)
{
	char	buf[5];
	int		ret;
	int		y;

	y = 0;
	while (y < 4)
	{
		ft_bzero(buf, 5);
		ret = read(fd, buf, 5);
		if (ret != 5 || buf[4] != '\n' || !check_line(buf))
		{
			ft_memdel((void **)new_ttrm);
			return (-1);
		}
		ft_strncpy((*new_ttrm)->tab[y], buf, 4);
		y++;
	}
	return (0);
}

int				fill_ttrm(int fd, t_ttrm **new_ttrm)
{
	char	buf;
	int		ret;

	if (!(*new_ttrm = (t_ttrm*)ft_memalloc(sizeof(t_ttrm) * 1)))
		return (-1);
	if (read_ttrm_lines(fd, new_ttrm) == -1)
	{
		ft_memdel((void **)new_ttrm);
		return (-1);
	}
	ret = read(fd, &buf, 1);
	if (ret == -1 || (buf != '\n' && ret > 0)
			|| !check_ttrm_block(*new_ttrm))
	{
		ft_memdel((void **)new_ttrm);
		return (-1);
	}
	normalize_ttrm(*new_ttrm);
	if (ret == 0)
		return (0);
	return (1);
}
