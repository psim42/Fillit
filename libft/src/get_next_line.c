/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:50:44 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/01 09:38:12 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int			fd_inf_cmp(t_list *elem1, t_list *elem2)
{
	t_fd_inf	*fd_inf_e1;
	t_fd_inf	*fd_inf_e2;

	fd_inf_e1 = ((t_fd_inf*)(elem1->content));
	fd_inf_e2 = ((t_fd_inf*)(elem2->content));
	return (fd_inf_e1->fd - fd_inf_e2->fd);
}

static t_fd_inf		*find_fd_inf(t_list **files_lst,
		t_list *to_find)
{
	t_list			*find_res;

	find_res = ft_lstfindoradd(files_lst, to_find, fd_inf_cmp);
	if (find_res == to_find)
	{
		((t_fd_inf*)(to_find->content))->buf_len = 0;
		((t_fd_inf*)(to_find->content))->buf =
			(char*)ft_memalloc(sizeof(char) * BUFF_SIZE);
		if (((t_fd_inf*)(to_find->content))->buf == NULL)
		{
			ft_lstremove(files_lst, to_find, ft_deflstdel);
			return (NULL);
		}
		else
		{
			return ((t_fd_inf*)(to_find->content));
		}
	}
	else
	{
		ft_lstdelone(&to_find, ft_deflstdel);
		return ((t_fd_inf*)(find_res->content));
	}
}

static t_fd_inf		*find_or_del_buffer(const int fd, char its_del)
{
	static t_list	*files_lst = NULL;
	t_list			*to_find;
	t_list			*find_res;

	to_find = ft_lstallocnew(sizeof(t_fd_inf));
	if (to_find == NULL)
	{
		return (NULL);
	}
	((t_fd_inf*)(to_find->content))->fd = fd;
	if (its_del == TRUE)
	{
		find_res = ft_lstfind(files_lst, to_find, fd_inf_cmp);
		if (find_res != NULL)
		{
			ft_memdel((void**)(&(((t_fd_inf*)(find_res->content))->buf)));
			ft_lstremove(&files_lst, find_res, ft_deflstdel);
		}
		ft_lstdelone(&to_find, ft_deflstdel);
		return ((t_fd_inf*)(&files_lst));
	}
	else
	{
		return (find_fd_inf(&files_lst, to_find));
	}
}

static int			add_str_to_lst(t_list **lst, char *buf, ssize_t *buf_len)
{
	ssize_t		str_len;
	t_list		*new_elem;
	char		endl_found;

	if (lst == NULL || buf == NULL)
		return (-1);
	if (*buf_len == 0)
		return (0);
	endl_found = FALSE;
	str_len = 0;
	while (str_len < *buf_len && buf[str_len] != '\n')
		++str_len;
	if (str_len < *buf_len)
		endl_found = TRUE;
	if ((new_elem = ft_lstnew(buf, str_len)) == NULL)
		return (-1);
	if (*lst == NULL)
		ft_lstadd(lst, new_elem);
	else
		ft_lstaddafter(ft_lstlast(*lst), new_elem);
	ft_memmove(buf, buf + (endl_found == TRUE ? str_len + 1 : 0),
			*buf_len - str_len - (endl_found == TRUE ? 1 : 0));
	*buf_len -= (str_len + (endl_found == TRUE ? 1 : 0));
	return (endl_found == TRUE ? 2 : 1);
}

int					get_next_line(const int fd, char **line)
{
	t_fd_inf	*fd_inf;
	int			add_ret;
	t_list		*str_lst;

	if (line == NULL)
		return (find_or_del_buffer(fd, TRUE) == NULL ? -1 : 0);
	if (BUFF_SIZE <= 0 || (fd_inf = find_or_del_buffer(fd, FALSE)) == NULL)
		return (-1);
	str_lst = NULL;
	add_ret = add_str_to_lst(&str_lst, fd_inf->buf, &(fd_inf->buf_len));
	while (add_ret != -1 && add_ret != 2 && (add_ret == 1
				|| (fd_inf->buf_len = read(fd, fd_inf->buf, BUFF_SIZE)) > 0))
		add_ret = add_str_to_lst(&str_lst, fd_inf->buf, &(fd_inf->buf_len));
	if (add_ret != -1 && str_lst == NULL && fd_inf->buf_len == 0)
		return (find_or_del_buffer(fd, TRUE) == NULL ? -1 : 0);
	if (add_ret == -1 || fd_inf->buf_len == -1
			|| ((*line = ft_lststrjoin(str_lst)) == NULL))
	{
		fd_inf->buf_len = 0;
		ft_lstdel(&str_lst, ft_deflstdel);
		return (-1);
	}
	ft_lstdel(&str_lst, ft_deflstdel);
	return (1);
}
