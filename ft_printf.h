/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:15:59 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/01/25 14:53:02 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c, int *ret);
int	ft_putstr(char *str, int *ret);
int	ft_putmem(unsigned long dir, int *ret);
int	ft_putnbr(int n, int *ret);
int	ft_putunbr(unsigned int n, int *ret);
int	ft_puthex(unsigned int n, int *ret);
int	ft_puthexcap(unsigned int n, int *ret);
int	ft_printf(char const *str, ...);

#endif
