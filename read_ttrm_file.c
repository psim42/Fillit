/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dCheck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:14:37 by psim              #+#    #+#             */
/*   Updated: 2018/11/30 15:49:11 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_ttrm	**fd_to_ttrm_tab(int fd)
{
	int ret;
	int i;
	char buf[1];

	t_ttrm **tab = (t_ttrm**)malloc(sizeof(t_ttrm*) * 27);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (fill_ttrm(fd, &(tab[i])))
	{
		ret = read(fd, buf, 1);
		if (ret = 0)
			return (0);

/*
a finir
*/

static int	check_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '#' || str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		fill_ttrm(int fd, s_ttrm **new_ttrm)
{
	int		i;
	int		y;
	char	buf[5];
	int		ret;


	x = 0;
	y = 0;
	if (!(*new_ttrm = (t_ttrm*)malloc(sizeof(t_ttrm) * 1)))
		return (NULL);
	ft_bzero(buf, 5);
	while (y < 4)
	{
		ret = read(fd, buf, 5);
		if (ret != 5 || bf[4] != '\n' || !check_line(buf))
		{
			free(*new_ttrm);
			return (-1);
		}
		ft_strncpy(new_ttrm->tab[y], buf, 4);
		y++;
		ft_bzero(buf, 5);
	}
	ret = read(fd, buf, 1);
	if (ret == 0)
		return (0);
	if (ret == -1 || buf[0] != '\n')
	{
		free(*new_ttrm);
		return (-1);
	}
	return (1);
}
