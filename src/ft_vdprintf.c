/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 22:10:19 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

int dprintf_put_nbr(size_t n, int fd);
int dprintf_put_hex(size_t n, const char *hex, int fd);
int dprintf_put_str(char *s, int fd);
int dprintf_ptr(uintptr_t ptr, int fd);
int	dprintf_putchar(char c, int fd);

static int	dprintf_format_u(long n, int fd)
{
	if (n < 0)
		return (dprintf_put_nbr((size_t)UINT_FAST32_MAX + n + 1, fd));
	return (dprintf_put_nbr((size_t)n, fd));
}

static int	dprintf_format_di(long n, int fd)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = dprintf_put_str(str, fd);
	free(str);
	return (len);
}

static int	specifier(va_list args, int specifier, int *size, int fd)
{
	int	check;

	check = 0;
	if (specifier == 'c')
		check = dprintf_putchar(va_arg(args, int), fd);
	if (specifier == 's')
		check = dprintf_put_str(va_arg(args, char *), fd);
	if (specifier == 'p')
		check = dprintf_ptr(va_arg(args, uintptr_t), fd);
	if ((specifier == 'd') || (specifier == 'i'))
		check = dprintf_format_di((long)va_arg(args, int), fd);
	if (specifier == 'u')
		check = dprintf_format_u((long)va_arg(args, unsigned int), fd);
	if (specifier == 'x')
		check = dprintf_put_hex(va_arg(args, unsigned int), HEX_LOWER, fd);
	if (specifier == 'X')
		check = dprintf_put_hex(va_arg(args, unsigned int), HEX_UPPER, fd);
	if (specifier == '%')
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
			if (*(format + 1) && specifier(args, *(++format), &size, fd) < 0)
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
