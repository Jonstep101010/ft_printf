/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jonas.paul.schwabe@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:45:40 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/29 11:29:28 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list args)
{
	int	c;

	c = va_arg(args, int);
	if (write (1, &c, 1) != FAIL)
		return (1);
	return (-1);
}

int	format_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	return (put_str(str));
}

int	format_u(va_list args)
{
	int	n;
	int	length;

	n = va_arg(args, unsigned int);
	if (n < 0)
		n = UINT_FAST32_MAX + n + 1;
	length = put_ultoa_count(n);
	if (length == FAIL)
		return (FAIL);
	return (length);
}

int	format_di(va_list args)
{
	char	*str;
	int		length;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (-1);
	length = put_str(str);
	free(str);
	return (length);
}

int	format_percent(va_list args)
{
	(void)args;
	return (ft_putchar('%'));
}
