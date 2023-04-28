/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:23:58 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/28 16:59:05 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIER "cspdiuxX%"
# define MARKER	'%'

# define FAIL -1
// # define WRITE_FAIL -17
// # define SUCCESS 0

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef int	(*t_format)(va_list);

int		ft_printf(const char *format, ...);

int		format_c(va_list args);
int		format_string(va_list args);
int		format_p(va_list args);
int		format_di(va_list args);
int		format_u(va_list args);

int		format_x(va_list args);
int		format_upperx(va_list args);
int		format_percent(va_list args);

int		put_ultoa_count(unsigned int n);
int		put_hex(size_t ptr, char *base);
int		put_str(char *s);
#endif