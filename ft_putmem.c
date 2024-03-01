/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:11:21 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/01/25 14:56:05 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_putlonghex(unsigned long dir, int *ret)
{
	char	num;

	if (dir >= 16)
	{
		if (ft_putlonghex(dir / 16, ret) == -1)
			return (-1);
		if (ft_putlonghex(dir % 16, ret) == -1)
			return (-1);
	}
	else
	{
		if (dir > 9)
		{
			num = dir % 10 + 'a';
			*ret += 1;
			return (write(1, &num, 1) == -1);
		}
		else
		{
			num = dir + '0';
			*ret += 1;
			return (write(1, &num, 1) == -1);
		}
	}
	return (1);
}

int	ft_putmem(unsigned long dir, int *ret)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	*ret += 2;
	if (ft_putlonghex(dir, ret) == -1)
		return (-1);
	return (1);
}
