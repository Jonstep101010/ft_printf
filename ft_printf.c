/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:13 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/27 19:34:11 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_formatter(va_list args, int specifier)
{
	int	check;
	
	if (specifier == 'c')
		check = format_c(args);
	if (specifier == 's')
		check = format_string(args);
	if (specifier == 'p')
		check = format_p(args);
	if (specifier == '%')
		check = write(1, &specifier, 1);
	if (specifier == 'd' || specifier == 'i')
		check = format_di(args);
	if (specifier == 'u')
		check = format_u(args);
	if (specifier == 'x' || specifier == 'X')
		check = put_hex((size_t)va_arg(args, unsigned int), specifier);
	return (check);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			size;
	int			i;
	int			check;

	i = 0;
	size = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == MARKER)
		{
			if (format[i + 1] == '\0')
				break ;
			check = check_formatter(args, format[++i]);
			if (check == -1)
				return (-1);
			size += check;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
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