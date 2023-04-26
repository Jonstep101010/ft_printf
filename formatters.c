/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:45:40 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/26 20:05:35 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list args)
{
	int	c;

	c = va_arg(args, int);
	if (write (1, &c, 1) != -1)
		return (1);
	return (-1);
}

int	format_string(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) != -1)
			i++;
		else
			return (-1);
	}
	return (ft_strlen(str));
}

int	format_p(va_list args)
{
	void	*ptr;
	int		length;

	ptr = va_arg(args, char *);
	ft_putstr_fd("0x", 1);
	length = 2;
	length += put_hex((size_t)ptr, 'x');
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

	n = va_arg(args, unsigned int);
	if (n < 0)
		n = UINT_FAST32_MAX + n + 1;
	return (put_ultoa_count(n));
}
