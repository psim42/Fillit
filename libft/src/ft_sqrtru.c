/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtru.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:19:06 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/03 15:26:18 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrtru(int nb)
{
	int current_num;
	int last_result;

	if (nb < 0)
		return (0);
	else if (nb >= 2147395600)
		return (46340);
	current_num = 0;
	last_result = 0;
	while (last_result < nb)
	{
		++current_num;
		last_result = current_num * current_num;
	}
	return (current_num);
}
