/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:45:40 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/20 18:49:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_p(va_list args)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_fd(va_arg(args, unsigned long), 1);
	return (1);
}

int	format_d(va_list args)
{
	ft_putnbr_fd(va_arg(args, int), 1);
	return (1);
}

int	format_c(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

int	format_string(va_list args)
{
	ft_putstr_fd(va_arg(args, char *), 1);
	return (ft_strlen(va_arg(args, char *)));
}
