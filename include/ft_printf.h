/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:23:58 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 21:31:15 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FAIL -1

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <string.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

int		ft_printf(const char *format, ...);
#endif