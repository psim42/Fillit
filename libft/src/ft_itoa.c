/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:51:25 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/19 14:00:16 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	nbr_len(int nb)
{
	int		size;

	size = 1;
	while (nb >= 10 || nb <= -10)
	{
		nb /= 10;
		++size;
	}
	return (size + (nb < 0 ? 1 : 0));
}

char		*ft_itoa(int n)
{
	int		nb_sign;
	int		nb_size;
	char	*nb_str;
	int		rev_index;

	nb_sign = (n < 0 ? -1 : 1);
	nb_size = nbr_len(n);
	nb_str = ft_strnew(nb_size);
	if (nb_str == NULL)
	{
		return (NULL);
	}
	nb_str[nb_size] = '\0';
	if (nb_sign < 0)
	{
		nb_str[0] = '-';
	}
	rev_index = 0;
	while (rev_index < (nb_size - (nb_sign < 0 ? 1 : 0)))
	{
		nb_str[nb_size - 1 - rev_index] = '0' + ((n % 10) * nb_sign);
		n /= 10;
		++rev_index;
	}
	return (nb_str);
}
