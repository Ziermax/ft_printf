/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:51:32 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/01/25 14:51:43 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n, int *ret)
{
	char	num;

	if (n > 9)
	{
		num = n % 10 + '0';
		if (ft_putunbr(n / 10, ret) == -1)
			return (-1);
		*ret += 1;
		return (write(1, &num, 1));
	}
	num = n + '0';
	*ret += 1;
	return (write(1, &num, 1));
}
