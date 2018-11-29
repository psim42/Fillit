/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:22:35 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/09 13:20:17 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int unit_digit;

	if (n >= 10 || n <= -10)
	{
		unit_digit = n % 10;
		if (unit_digit < 0)
		{
			unit_digit *= -1;
		}
		ft_putnbr(n / 10);
		ft_putchar('0' + unit_digit);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		ft_putchar('0' + n);
	}
}
