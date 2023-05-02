/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/02 20:42:42 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(size_t n, char *base, size_t slen)
{
	int	size;

	size = 0;
	if (n >= slen)
	{
		size += put_nbr(n / slen, base, slen);
		if (size < 0)
			return (FAIL);
	}
	size += ft_putchar(base[n % slen]);
	return (size);
}

int	put_str(char *s)
{
	if (!s)
		s = "(null)";
	if (write(1, s, ft_strlen(s)) < 0)
		return (FAIL);
	return (ft_strlen(s));
}
