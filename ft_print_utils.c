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

#include "printf.h"

int		format_string(va_list args);
int		format_p(va_list args);
int		format_d(va_list args);
int		format_i(va_list args);
int		format_u(va_list args);
int		format_x(va_list args);
int		format_upperx(va_list args);
int		format_percent(va_list args);