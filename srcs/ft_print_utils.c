/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:45:40 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/20 18:49:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_i(va_list args)
{
	ft_putnbr_fd(va_arg(args, int), 1);
	return (1);
}

int	format_u(va_list args)
{
	ft_putnbr_fd(va_arg(args, unsigned int), 1);
	return (1);
}

int	format_x(va_list args)
{
	ft_putnbr_fd(va_arg(args, unsigned int), 1);
	return (1);
}

int	format_upperx(va_list args)
{
	ft_putnbr_fd(va_arg(args, unsigned int), 1);
	return (1);
}

int	format_percent(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}
