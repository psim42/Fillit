/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:18:40 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 14:39:45 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (s != NULL && f != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			(*f)(index, &(s[index]));
			++index;
		}
	}
}
