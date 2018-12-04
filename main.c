/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:16:29 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/04 09:20:13 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

static void		print_error(void)
{
	ft_putendl("error");
}

static void		print_usage(void)
{
	ft_putendl("usage: fillit list_of_tetrominos_file_name");
}

static void		free_map_and_ttrm_list(t_map *map, t_ttrm **ttrm_tab)
{
	if (map != NULL)
	{
		free_map_content(map);
		ft_memdel((void**)(&map));
	}
	if (ttrm_tab != NULL)
	{
		free_ttrm_tab(ttrm_tab);
	}
}

int				main(int argc, char **argv)
{
	int		fd;
	t_ttrm	**ttrm_tab;
	t_map	*result;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) >= 0)
		{
			ttrm_tab = fd_to_ttrm_tab(fd);
			close(fd);
			if (ttrm_tab != NULL)
				if ((result = resolve_fillit(ttrm_tab)) != NULL)
				{
					print_map(result);
					free_map_and_ttrm_list(result, ttrm_tab);
					return (0);
				}
			free_map_and_ttrm_list(NULL, ttrm_tab);
		}
		print_error();
		return (0);
	}
	print_usage();
	return (0);
}
