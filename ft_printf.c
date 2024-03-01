/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:09:49 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/01/26 18:00:09 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percentge(va_list ap, char const **s, int *ret)
{
	if (*(*s + 1) == 'c')
		return (ft_putchar(va_arg(ap, int), ret));
	else if (*(*s + 1) == 's')
		return (ft_putstr(va_arg(ap, char *), ret));
	else if (*(*s + 1) == 'p')
		return (ft_putmem(va_arg(ap, long), ret));
	else if (*(*s + 1) == 'd')
		return (ft_putnbr(va_arg(ap, int), ret));
	else if (*(*s + 1) == 'i')
		return (ft_putnbr(va_arg(ap, int), ret));
	else if (*(*s + 1) == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int), ret));
	else if (*(*s + 1) == 'x')
		return (ft_puthex(va_arg(ap, long), ret));
	else if (*(*s + 1) == 'X')
		return (ft_puthexcap(va_arg(ap, long), ret));
	else if (*(*s + 1) == '%')
	{
		*ret += 1;
		return (write(1, "%", 1));
	}
	else
		return (0 - (int)(*s -= 1));
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_percentge(ap, &str, &ret) == -1)
				return (-1);
			str += 1;
		}
		else
		{
			ret++;
			if (write(1, str, 1) == -1)
				return (-1);
		}
		str++;
	}
	va_end(ap);
	return (ret);
}
