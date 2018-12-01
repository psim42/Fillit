/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:16:29 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/01 12:45:36 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	t_ttrm **ttrm_tab = fd_to_ttrm_tab(fd);

	/*ttrm_tab = malloc(sizeof(*ttrm_tab) * 3);
	ttrm_tab[0] = malloc(sizeof(**ttrm_tab));
	ttrm_tab[1] = malloc(sizeof(**ttrm_tab));
	ttrm_tab[2] = NULL;

	for (int lol = 0; lol < 2; ++lol)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				ttrm_tab[lol]->tab[i][j] = 'A' + lol;
			}
		}
	}*/
	if (ttrm_tab == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		for (int lol = 0; ttrm_tab[lol] != NULL; ++lol)
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					printf("%c", ttrm_tab[lol]->tab[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	free_ttrm_tab(ttrm_tab);

	return (0);
}
