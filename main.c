/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:16:29 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/03 13:50:53 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

static void		print_error()
{
	ft_putendl("error");
}

static void		print_usage()
{
	ft_putendl("usage: fillit list_of_tetrominos_file_name");
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
			{
				if ((result = resolve_fillit(ttrm_tab)) != NULL)
				{
					print_map(result);
					return (0);
				}
			}
		}
		print_error();
		return (0);
	}
	print_usage();
	return (0);
}
