/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:29:15 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/01/25 16:43:33 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int *ret)
{
	char	num;

	if (n >= 16)
	{
		if (ft_puthex(n / 16, ret) == -1)
			return (-1);
		if (ft_puthex(n % 16, ret) == -1)
			return (-1);
	}
	else
	{
		if (n > 9)
		{
			num = n % 10 + 'a';
			*ret += 1;
			return (write(1, &num, 1));
		}
		else
		{
			num = n + '0';
			*ret += 1;
			return (write(1, &num, 1));
		}
	}
	return (1);
}
