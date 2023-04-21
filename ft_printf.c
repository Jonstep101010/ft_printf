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

static void	check_formatter(t_format *formatter)
{
	*formatter++ = format_c;
	*formatter++ = format_string;
	*formatter++ = format_p;
	*formatter++ = format_d;
	*formatter++ = format_i;
	*formatter++ = format_u;
	*formatter++ = format_x;
	*formatter++ = format_upperx;
	*formatter++ = format_percent;
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	int			size;
	t_format	formatter[9];
	char		*contains;

	i = 0;
	check_formatter(formatter);
	contains = (char *) ft_strchr(SPECIFIER, format[i++]);
	va_start(args, format);
	size = 0;
	while (format[i] != '\0')
	{
		if ((format[i] == MARKER) && (ft_strchr(SPECIFIER, format[++i] != -1)))
		{
			size += formatter[contains - SPECIFIER](args);
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

	// int			*contains;
	// contains = (int *) ft_strchr(SPECIFIER, format[++i] != -1);