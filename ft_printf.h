/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:23:58 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/02 20:59:17 by jschwabe         ###   ########.fr       */
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
# include <string.h>

typedef int	(*t_format)(va_list);

int		ft_printf(const char *format, ...);

// int		format_p(size_t *ptr);
// int		format_di(long n);
// int		format_u(long n);

int		put_nbr(size_t n, char *base, size_t slen);
int		put_str(char *s);
#endif