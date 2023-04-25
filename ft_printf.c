/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/25 19:42:32 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_formatter(va_list args, int specifier)
{
	if (specifier == 'c')
		return (format_c(args));
	if (specifier == 's')
		return (format_string(args));
	if (specifier == 'p')
		return (format_p(args));
	if (specifier == '%')
		return (ft_putchar_fd('%', 1), 1);
	if (specifier == 'd' || specifier == 'i')
		return (format_di(args));
	if (specifier == 'u')
		return (format_u(args));
	if (specifier == 'x' || specifier == 'X')
		return (put_hex(va_arg(args, size_t), specifier));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			size;
	int			i;

	i = 0;
	size = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == MARKER)
		{
			if (format[i + 1] == '\0')
				break ;
			size += check_formatter(args, format[++i]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			size++;
		}
		i++;
	}
	return (va_end(args), size);
}

//add stuff
/*
printf("%d\n", contains);
		size += formatters[SPECIFIER - ft_strchr(SPECIFIER, *(+format[i]))](args);}
					// printf("\nformat val: %c\b", format[i + 1]);
						// ptr = ft_strchr(SPECIFIER, *format[i] + 1) != -1);
	// contains = (int) ptr;
		// int			contains;
	// char		*ptr;
	// t_format	formatters[9];

	// *formatters++ = format_p;
	// *formatters++ = format_d;
	// *formatters++ = format_i;
	// *formatters++ = format_u;
	// *formatters++ = format_x;
	// *formatters++ = format_upperx;
	// *formatters++ = format_percent;

			// printf("\nget rekt haha%d\n", format_string(args));
				// if (specifier == 'p')
	// 	return (format_p(args));
		// printf("\nspecifier ft_: %d\n", specifier);
*/