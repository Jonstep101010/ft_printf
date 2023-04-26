/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:45:40 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/26 12:19:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	format_p(va_list args)
{
	void	*ptr;
	int		length;

	ptr = va_arg(args, char *);
	ft_putstr_fd("0x", 1);
	length = 2;
	length += put_hex_st((size_t)&*ptr);
	// printf("\n%p\n", ptr);
	// ptrint = ft_atoi(ptr);
	// printf("\n%p\n", &ptr);
	// free(ptr);
	return (length);
}

int	format_di(va_list args)
{
	char	*str;
	int		length;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return (length);
}

int	format_u(va_list args)
{
	unsigned int	n;
	unsigned int	copy;
	int				length;

	length = 0;
	n = va_arg(args, unsigned int);
	if (n < 0)
		n = UINT_FAST32_MAX + n + 1;
	copy = n;
	length += put_ultoa_count(n);
	while (copy > 9)
	{
		length++;
		copy /= 10;
	}
	return (length);
}

// int	format_x(va_list args, int specifier)
// {
// 	int	length;

// 	length = 0;
// 	length += put_hex(va_arg(args, size_t), specifier);
// 	return (length);
// }
// int		format_upperx(va_list args);
// int		format_percent(va_list args);

	// char	*ptr;
	// char	*string;
	// char	*hex_string;

	// ptr = "0123456789abcdef";
	// string = va_arg(args, void *);
	// if (!string)
	// 	ft_putstr_fd("0x0", 1);
	// while (*string != 0)
	// {
	// 	*hex_string = ptr[(unsigned long) string % 16];
	// 	(unsigned long *) string /= 16;
	// }
	// return ();