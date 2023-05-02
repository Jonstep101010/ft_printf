/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:40:48 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/30 15:21:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ultoa_count(unsigned int n)
{
	char	*nbrs;
	int		count;
	int		check;

	check = 0;
	count = 0;
	nbrs = "0123456789";
	if (n >= 10)
	{
		check = put_ultoa_count(n / 10);
		if (check == FAIL)
			return (-1);
		count += check;
		check = put_ultoa_count(n % 10);
		if (check == FAIL)
			return (-1);
		count += check;
	}
	else
	{
		if (write(1, (nbrs + n), 1) == FAIL)
			return (FAIL);
		count++;
	}
	return (count);
}

int	put_hex(size_t ptr, char *base)
{
	int			count;
	int			check;

	check = 0;
	count = 0;
	if (ptr > 15)
	{
		check = put_hex(ptr / 16, base);
		if (check == FAIL)
			return (-1);
		count += check;
		check = put_hex(ptr % 16, base);
		if (check == FAIL)
			return (-1);
		count += check;
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
