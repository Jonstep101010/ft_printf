/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:02:33 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 22:06:01 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_vdprintf(int fd, const char *format, va_list args);

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	va_list		ap_copy;
	int			size;

	va_start(ap, format);
	va_copy(ap_copy, ap);
	size = ft_vdprintf(fd, format, ap_copy);
	va_end(ap);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	va_list		ap_copy;
	int			size;

	va_start(ap, format);
	va_copy(ap_copy, ap);
	size = ft_vdprintf(1, format, ap_copy);
	va_end(ap);
	return (size);
}
