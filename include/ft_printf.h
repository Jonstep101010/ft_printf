/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:23:58 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/31 13:40:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIER "cspdiuxX%"
# define MARKER	'%'
# define FAIL -1

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <string.h>

int		ft_printf(const char *format, ...);

int		put_nbr(size_t n, char *base, size_t slen);
int		put_str(char *s);
#endif