/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/26 18:54:08 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ultoa_count(unsigned int n)
{
	char	*nbrs;
	int		count;

	count = 0;
	nbrs = "0123456789";
	if (n > 9)
	{
		count += put_ultoa_count(n / 10);
		count += put_ultoa_count(n % 10);
	}
	else
	{
		write(1, nbrs + n, 1);
		count++;
	}
	return (count);
}

int	put_hex(size_t ptr, int c)
{
	char		*base;
	int			count;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
	{
		count += put_hex(ptr / 16, c);
		count += put_hex(ptr % 16, c);
	}
	else
		count += write (1, (base + ptr), 1);
	return (count);
}
