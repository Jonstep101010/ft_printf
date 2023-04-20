/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/20 18:57:03 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_c(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

static void	check_formatter(va_list args)
{
	format_c(args);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	size_t		size;
	int			contains;

	i = 0;
	va_start(args, format);
	contains = (int) ft_strchr(SPECIFIER, *format + 1);
	size = ft_strlen(format);
	while (*format != '\0')
	{
		if ((*format == MARKER) && (contains))
		{
			check_formatter(args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(*format, 1);
		}
		format++;
	}
	va_end(args);
	return (size);
}

		// if (*string == DELIMITER && ft_strnchr(FORMATS, *(string + 1)) != -1)
		// 	length += formatters[ft_strnchr(FORMATS, *(++string))](ap);

/* int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(format);
	while (i < size)
	{
		if (format == '%')
		{
			if (check_SPECIFIERs(&format[i + 1]))
			{

				//allocate space for SPECIFIER?
				i += 2;
			}
		}
		else
			i++;
	}
	return (size);
} */


