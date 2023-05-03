/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jonas.paul.schwabe@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:23:58 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/03 10:30:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIER "cspdiuxX%"
# define MARKER	'%'
# define FAIL -1

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

int		put_nbr(size_t n, char *base, size_t slen);
int		put_str(char *s);
#endif