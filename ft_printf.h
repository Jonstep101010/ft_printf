/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:23:58 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/25 19:42:48 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIER "cspdiuxX%"
# define MARKER	'%'

# include "libft/libft.h"
# include <stdarg.h>

typedef int	(*t_format)(va_list);

int		ft_printf(const char *format, ...);

int		format_c(va_list args);
int		format_string(va_list args);
int		format_p(va_list args);
int		format_di(va_list args);
int		format_u(va_list args);
// int		format_x(va_list args);
// int		format_upperx(va_list args);
// int		format_percent(va_list args);
int		put_ultoa_count(unsigned int n);
// void	s_reverse(char *s);
int		put_hex(size_t ptr, int c);
#endif