/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 21:33:02 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdint.h>

int	printf_put_nbr(size_t n);
int	printf_put_hex(size_t n, const char *hex);
int	printf_put_str(char *s);
int	printf_ptr(uintptr_t ptr);

/*
@brief calls putnbr with specific parameters
@param n maintains org val
@return length returned by printf_put_nbr call (-1 if failure)
*/
static int	format_u(long n)
{
	if (n < 0)
		return (printf_put_nbr((size_t)UINT_FAST32_MAX + n + 1));
	return (printf_put_nbr((size_t)n));
}

/*
@brief formats integer for printing
@param n maintains org val
@return length of printed string (-1 if failure)
*/
static int	format_di(long n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = printf_put_str(str);
	free(str);
	return (len);
}

static int	check_formatter(va_list args, int specifier, int *size)
{
	int	check;

	check = 0;
	if (specifier == 'c')
		check = ft_putchar(va_arg(args, int));
	if (specifier == 's')
		check = printf_put_str(va_arg(args, char *));
	if (specifier == 'p')
		check = printf_ptr(va_arg(args, uintptr_t));
	if ((specifier == 'd') || (specifier == 'i'))
		check = format_di((long)va_arg(args, int));
	if (specifier == 'u')
		check = format_u((long)va_arg(args, unsigned int));
	if (specifier == 'x')
		check = printf_put_hex(va_arg(args, unsigned int), HEX_LOWER);
	if (specifier == 'X')
		check = printf_put_hex(va_arg(args, unsigned int), HEX_UPPER);
	if (specifier == '%')
		check = ft_putchar('%');
	if (check < 0)
		return (FAIL);
	return (*size += check);
}

/*
@brief basic functionality of printf
@param input, formatted input
@return length (-1 if failure)
*/
int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			size;

	size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) && check_formatter(args, *(++format), &size) < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(*format) <= FAIL)
				return (-1);
			size++;
		}
		format++;
	}
	return (va_end(args), size);
}
