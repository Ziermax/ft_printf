/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:51:21 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/01/25 14:51:14 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *ret)
{
	char	num;

	if (n == -2147483648)
	{
		*ret += 11;
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		*ret += 1;
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
	}
	if (n > 9)
	{
		num = n % 10 + '0';
		if (ft_putnbr(n / 10, ret) == -1)
			return (-1);
		*ret += 1;
		return (write(1, &num, 1) == -1);
	}
	num = n + '0';
	*ret += 1;
	return (write(1, &num, 1));
}
