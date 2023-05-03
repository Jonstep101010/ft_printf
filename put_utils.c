/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jonas.paul.schwabe@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/03 10:19:36 by jschwabe         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) == FAIL)
			return (FAIL);
		i++;
	}
	return (i);
}
