/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/25 19:53:02 by jschwabe         ###   ########.fr       */
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
		count++;
		put_ultoa_count(n / 10);
		put_ultoa_count(n % 10);
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
	char	*base;
	size_t	len;
	int		count;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	len = ft_strlen(base);
	if (ptr >= len)
	{
		count += put_hex(ptr / len, c);
		count += put_hex(ptr % len, c);
	}
	else
	{
		count++;
		write (1, (base + ptr), 1);
	}
	return (count);
}

/* void	s_reverse(char *s)
{
	char	tmp;
	int		i;
	int		len;

	len = ft_strlen(s) - 1;
	i = 0;
	while (i <= len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i];
		s[len - i] = tmp;
		i++;
	}
} */
