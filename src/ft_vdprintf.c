/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 23:58:21 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

int		dprintf_put_nbr(size_t n, int fd);
int		dprintf_put_hex(unsigned int n, const char *hex, int fd);
int		dprintf_put_str(const char *s, int fd);
int		dprintf_ptr(uintptr_t ptr, int fd);
int		dprintf_putchar(char c, int fd);
char	*ft_ltoa(long n);

int	dprintf_format_u(long n, int fd)
{
	if (n < 0)
		return (dprintf_put_nbr((size_t)UINT_FAST32_MAX + n + 1, fd));
	return (dprintf_put_nbr((size_t)n, fd));
}

int	dprintf_format_di(long n, int fd)
{
	char	*str;
	int		len;

	str = ft_ltoa(n);
	if (!str)
		return (-1);
	len = dprintf_put_str(str, fd);
	free(str);
	return (len);
}

int	specifier(va_list *args, int specifier, int *size, int fd)
{
	int	check;

	check = 0;
	if (specifier == 'c')
		check = dprintf_putchar(va_arg(*args, int), fd);
	(void)specifier, (void)fd;
	if (specifier == 's')
		check = dprintf_put_str(va_arg(*args, const char *), fd);
	else if (specifier == 'p')
		check = dprintf_ptr(va_arg(*args, uintptr_t), fd);
	else if ((specifier == 'd') || (specifier == 'i'))
		check = dprintf_format_di((long)va_arg(*args, int), fd);
	else if (specifier == 'u')
		check = dprintf_format_u((long)va_arg(*args, unsigned int), fd);
	else if (specifier == 'x')
		check = dprintf_put_hex(va_arg(*args, unsigned int), HEX_LOWER, fd);
	else if (specifier == 'X')
		check = dprintf_put_hex(va_arg(*args, unsigned int), HEX_UPPER, fd);
	else if (specifier == '%')
		check = dprintf_putchar('%', fd);
	if (check < 0)
		return (FAIL);
	return (*size += check);
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int			size;

	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (specifier(&args, (int)*format, &size, fd) < 0)
				return (-1);
		}
		else
		{
			dprintf_putchar(*format, fd);
			size++;
		}
		format++;
	}
	return (size);
}
