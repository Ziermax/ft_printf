/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:18:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/01/25 14:54:39 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int *ret)
{
	if (!str)
	{
		*ret += 6;
		return (write(1, "(null)", 6));
	}
	while (*str)
	{
		*ret += 1;
		if (write(1, str++, 1) == -1)
			return (-1);
	}
	return (1);
}
