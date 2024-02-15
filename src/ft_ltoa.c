/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:30:29 by jschwabe          #+#    #+#             */
/*   Updated: 2024/02/14 21:46:04 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ndigits(long int n)
{
	size_t		digits;
	long int	num;

	num = n;
	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	if (num < 0)
		digits++;
	return (digits);
}

static char	*convert_long(char *s, size_t digits, long long num)
{
	int	sign;

	sign = 1;
	if (num < 0)
	{
		*s = '-';
		num *= -1;
		sign = -1;
	}
	while (digits--)
	{
		*(s + digits) = num % 10 + '0';
		num /= 10;
	}
	if (sign == -1)
		*s = '-';
	return (s);
}

char	*ft_ltoa(long n)
{
	size_t		digits;
	char		*s;
	long long	num;

	num = n;
	digits = ndigits(num);
	s = malloc(sizeof(char) * (digits + 1));
	if (!s)
		return (NULL);
	s[digits] = '\0';
	return (convert_long(s, digits, num));
}
