/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckandy <ckandy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 05:01:53 by ckandy            #+#    #+#             */
/*   Updated: 2021/12/15 18:19:58 by ckandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_u(unsigned int x)
{
	int	i;

	i = 0;
	if (x >= 10)
	{
		if (x >= 10 && x <= 15)
		{
			i += ft_putchar(x + 65 - 10);
			return (i);
		}
		else
		{
			i += ft_hex_u(x / 16);
			i += ft_hex_u((x % 16));
			return (i);
		}
	}
	else
		i += ft_putchar(x + 48);
	return (i);
}

int	ft_symbol(const char s, va_list arg)
{
	if (s == '%')
		return (ft_putchar('%'));
	if (s == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (s == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (s == 'p')
		return (ft_hex_p(va_arg(arg, unsigned long long)));
	if (s == 'x')
		return (ft_hex_l(va_arg(arg, unsigned int)));
	if (s == 'X')
		return (ft_hex_u(va_arg(arg, unsigned int)));
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;
	int		i;

	done = 0;
	i = 0;
	va_start (arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			done += ft_symbol(format[++i], arg);
			i++;
		}
		else
		{
			done += ft_putchar(format[i]);
			i++;
		}
	}
	va_end (arg);
	return (done);
}
