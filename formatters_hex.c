/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:32:44 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/28 14:35:55 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_p(va_list args)
{
	void	*ptr;
	int		length;

	ptr = va_arg(args, char *);
	length = put_str("0x");
	if (length != FAIL)
		length += put_hex((size_t)ptr, "0123456789abcdef");
	if (length < 2)
		return (FAIL);
	return (length);
}

int	format_x(va_list args)
{
	return (put_hex((size_t)va_arg(args, unsigned int), "0123456789abcdef"));
}

int	format_upperx(va_list args)
{
	return (put_hex((size_t)va_arg(args, unsigned int), "0123456789ABCDEF"));
}