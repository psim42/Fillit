/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:57:42 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/14 12:03:28 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_num_sign(const char *str, int *index)
{
	int		num_sign;

	if (str[*index] == '+')
	{
		num_sign = 1;
		++(*index);
	}
	else if (str[*index] == '-')
	{
		num_sign = -1;
		++(*index);
	}
	else
	{
		num_sign = 1;
	}
	return (num_sign);
}

int			ft_atoi(const char *str)
{
	int		number;
	int		index;
	int		num_sign;

	number = 0;
	index = 0;
	while (str[index] == ' ' || str[index] == '\t'
			|| str[index] == '\n' || str[index] == '\v'
			|| str[index] == '\f' || str[index] == '\r')
	{
		++index;
	}
	num_sign = get_num_sign(str, &index);
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += (str[index] - '0') * num_sign;
		++index;
	}
	return (number);
}
