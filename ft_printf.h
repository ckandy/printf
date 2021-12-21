/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckandy <ckandy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 04:59:12 by ckandy            #+#    #+#             */
/*   Updated: 2021/12/15 18:22:31 by ckandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_check(const char *str, va_list arg);
int		ft_symbol(const char s, va_list arg);
size_t	ft_strlen(const char *str);
int		ft_putchar(char x);
int		ft_putstr(char *str);
int		ft_putnbr(long long x);
char	*ft_strchr(const char *s, int c);
int		ft_hex_l(unsigned long long x);
int		ft_hex_p(unsigned long long x);

#endif
