/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:16:27 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/09 13:28:23 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int unit_digit;

	if (n >= 10 || n <= -10)
	{
		unit_digit = n % 10;
		if (unit_digit < 0)
		{
			unit_digit *= -1;
		}
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + unit_digit, fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		ft_putchar_fd('0' + n, fd);
	}
}
