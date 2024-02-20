/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 23:58:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	dprintf_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	dprintf_put_nbr(size_t n, int fd)
{
	int	size;

	size = 0;
	if (n >= 10)
	{
		size += dprintf_put_nbr(n / 10, fd);
		if (size < 0)
			return (FAIL);
	}
	size += dprintf_putchar(DECIMAL[n % 10], fd);
	return (size);
}

int	dprintf_put_hex(unsigned int n, const char *hex, int fd)
{
	int	size;

	size = 0;
	if (n >= 16)
	{
		size += dprintf_put_hex(n / 16, hex, fd);
		if (size < 0)
			return (FAIL);
	}
	size += dprintf_putchar(hex[n % 16], fd);
	return (size);
}

int	dprintf_put_str(const char *s, int fd)
{
	size_t	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len] != '\0')
	{
		if (dprintf_putchar(s[len], fd) < 0)
			return (FAIL);
		len++;
	}
	return (len);
}

int	dprintf_ptr(uintptr_t ptr, int fd)
{
	int			len;

	len = dprintf_put_str("0x", fd);
	if (ptr == 0)
		return (dprintf_putchar('0', fd) + len);
	len += dprintf_put_hex(ptr, HEX_LOWER, fd);
	return (len);
}
