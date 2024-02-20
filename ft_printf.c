/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:02:33 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 23:58:30 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_vdprintf(int fd, const char *format, va_list args);

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			size;

	va_start(ap, format);
	size = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			size;

	va_start(ap, format);
	size = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (size);
}
