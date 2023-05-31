/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/31 14:00:28 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
@brief calls putnbr with specific parameters
@param n maintains org val
@return length returned by put_nbr call (-1 if failure)
*/
static int	format_u(long n)
{
	if (n < 0)
		return (put_nbr((size_t)UINT_FAST32_MAX + n + 1, "0123456789", 10));
	return (put_nbr((size_t)n, "0123456789", 10));
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
	len = put_str(str);
	free(str);
	return (len);
}

/*
@brief formats for printing memory address of ptr
@param ptr to get mem for
@return length of printing (-1 if failure)
*/
static int	format_p(size_t *ptr)
{
	int		len;

	len = put_str("0x");
	if (len < 2)
		return (FAIL);
	len += put_nbr((size_t)ptr, "0123456789abcdef", 16);
	return (len);
}

/*check specifier for formatting functions*/
static int	check_formatter(va_list args, int specifier, int *size)
{
	int	check;

	check = 0;
	if (specifier == 'c')
		check = ft_putchar(va_arg(args, int));
	if (specifier == 's')
		check = put_str(va_arg(args, char *));
	if (specifier == 'p')
		check = (format_p(va_arg(args, void *)));
	if ((specifier == 'd') || (specifier == 'i'))
		check = format_di((long)va_arg(args, int));
	if (specifier == 'u')
		check = format_u((long)va_arg(args, unsigned int));
	if (specifier == 'x')
		check = put_nbr(va_arg(args, unsigned int), "0123456789abcdef", 16);
	if (specifier == 'X')
		check = put_nbr(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
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
		if (*format == MARKER)
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
