/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/28 19:31:00 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

/*check specifier for formatting functions*/
static int	check_formatter(va_list args, int specifier)
{
	int	check;

	if (specifier == 'c')
		check = format_c(args);
	if (specifier == 's')
		check = format_string(args);
	if (specifier == 'p')
		check = format_p(args);
	if (specifier == 'd')
		check = format_di(args);
	if (specifier == 'i')
		check = format_di(args);
	if (specifier == 'u')
		check = format_u(args);
	if (specifier == 'x')
		check = format_x(args);
	if (specifier == 'X')
		check = format_upperx(args);
	if (specifier == '%')
		check = format_percent(args);
	return (check);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			size;
	int			check;

	size = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if ((*format == MARKER) && (*(format + 1) != '\0'))
		{		
			check = check_formatter(args, *(++format));
			if (check == -1)
				return (-1);
			size += check;
		}
		else if ((write(1, &*format, 1) == -1) || (check == -1))
			return (-1);
		else
			size++;
		format++;
	}
	return (va_end(args), size);
}

/*t_format to functions for matching formatting*/
/* static void	assign_formats(t_format *formats)
{
	*formats++ = format_c;
	*formats++ = format_string;
	*formats++ = format_p;
	*formats++ = format_di;
	*formats++ = format_di;
	*formats++ = format_u;
	*formats++ = format_x;
	*formats++ = format_upperx;
	*formats++ = format_percent;
} */

/*Printf implementation using t_list instead of if statements*/
/* int	ft_printf(const char *string, ...)
{
	t_format	formats[9];
	va_list		args;
	int			check;
	int			size;

	assign_formats(formats);
	va_start(args, string);
	size = 0;
	while (*string)
	{
		if ((*string == MARKER) && (*(string + 1) != '\0') && \
		ft_strnchr(SPECIFIER, *(string + 1)) != -1)
		{
			check = (formats[ft_strnchr(SPECIFIER, *(++string))](args));
			if (check == -1)
				return (-1);
			size += check;
		}
		else if (((ft_putchar(*string)) == -1) || (check == FAIL))
			return (-1);
		else
			size++;
		string++;
	}
	return (va_end(args), size);
} */
