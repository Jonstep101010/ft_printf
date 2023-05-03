/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jonas.paul.schwabe@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:45:40 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/03 10:31:12 by jschwabe         ###   ########.fr       */
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

/*
@brief calls putnbr with specific parameters
@param n maintains org val
@return length returned by put_nbr call (-1 if failure)
*/
int	format_u(va_list args)
{
	long n;

	n = (long)va_arg(args, unsigned int);
	if (n < 0)
		return (put_nbr((size_t)UINT_FAST32_MAX + n + 1, "0123456789", 10));
	return (put_nbr((size_t)n, "0123456789", 10));
}

/*
@brief formats integer for printing
@param n maintains org val
@return length of printed string (-1 if failure)
*/
int	format_di(va_list args)
{
	long n;
	char	*str;
	int		len;

	n = (long)va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = put_str(str);
	free(str);
	return (len);
}

/*
@brief formats for printing memory address of ptr
@param ptr to get mem for
@return length of printing (-1 if failure)
*/
int	format_p(va_list args)
{
	int		len;
	void	*ptr;

	ptr = va_arg(args, void *);
	len = put_str("0x");
	if (len < 2)
		return (FAIL);
	return (len += put_nbr((size_t)ptr, "0123456789abcdef", 16));
}

int	format_percent(va_list args)
{
	(void)args;
	return (ft_putchar('%'));
}

int	format_x(va_list args)
{
	return (put_nbr((size_t)va_arg(args, unsigned int), "0123456789abcdef", 16));
}

int	format_upperx(va_list args)
{
	return (put_nbr((size_t)va_arg(args, unsigned int), "0123456789ABCDEF", 16));
}
