/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tformat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:18:49 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/02 16:21:30 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "ft_printf.h"*/

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