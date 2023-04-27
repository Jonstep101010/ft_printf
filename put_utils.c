/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/27 19:48:04 by jschwabe         ###   ########.fr       */
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
		if (write(1, (nbrs + n3), 1) == FAIL)
			return (FAIL);
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
	{
		if (write(1, (base + ptr), 1) == FAIL)
			return (FAIL);
		count++;
	}
	return (count);
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

// int	check_write(int check)
// {
// 	if (check != -1)
// 		return (0);
// 	return (check);
// }
