/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 21:31:03 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	printf_put_nbr(size_t n)
{
	int	size;

	size = 0;
	if (n >= 10)
	{
		size += printf_put_nbr(n / 10);
		if (size < 0)
			return (FAIL);
	}
	size += ft_putchar(DECIMAL[n % 10]);
	return (size);
}

int	printf_put_hex(size_t n, const char *hex)
{
	int	size;

	size = 0;
	if (n >= 16)
	{
		size += printf_put_hex(n / 16, hex);
		if (size < 0)
			return (FAIL);
	}
	size += ft_putchar(hex[n % 16]);
	return (size);
}

int	printf_put_str(char *s)
{
	if (!s)
		s = "(null)";
	if (write(1, s, ft_strlen(s)) < 0)
		return (FAIL);
	return (ft_strlen(s));
}

int	printf_ptr(uintptr_t ptr)
{
	int			len;

	len = printf_put_str("0x");
	if (ptr == 0)
		return (ft_putchar('0') + len);
	len += printf_put_hex(ptr, HEX_LOWER);
	return (len);
}
