/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckandy <ckandy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 02:50:02 by ckandy            #+#    #+#             */
/*   Updated: 2021/12/15 18:21:29 by ckandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char x)
{
	write(1, &x, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(long long x)
{
	size_t	i;

	i = 0;
	if (x < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(-x);
	}
	else if (x > 9)
	{
		i += ft_putnbr(x / 10);
		i += ft_putchar(x % 10 + '0');
	}
	else
	{
		i += ft_putchar(x + '0');
	}
	return (i);
}

int	ft_hex_l(unsigned long long x)
{
	int	i;

	i = 0;
	if (x >= 10)
	{
		if (x >= 10 && x <= 15)
		{
			i += ft_putchar(x + 97 - 10);
			return (i);
		}
		else
		{
			i += ft_hex_l(x / 16);
			i += ft_hex_l((x % 16));
			return (i);
		}
	}
	else
		i += ft_putchar(x + 48);
	return (i);
}

int	ft_hex_p(unsigned long long x)
{
	int	i;

	i = 0;
	i = ft_putstr("0x");
	i += ft_hex_l(x);
	return (i);
}
