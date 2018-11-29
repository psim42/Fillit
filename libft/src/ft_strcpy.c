/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:21:46 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/07 17:38:44 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int		index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		++index;
	}
	dst[index] = '\0';
	return (dst);
}
