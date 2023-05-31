/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:34:05 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/11 23:08:03 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	helper_isspace(char c)
{
	if ((c == 32) || ((c > 8) && (c < 14)))
		return (1);
	return (0);
}

static int	convert_to_int(char c, int *total)
{
	*total = (*total * 10) + (c - '0');
	return (*total);
}

static int	isprefix(char c)
{
	if ((c == '-') || (c == '+'))
		return (1);
	return (0);
}

/*
** @brief converts numbers in char str to integer
** @param str items to convert
** @return integer * notation (-prefix if found)
** @details only allows for one sign (+ or -) in front of numbers in string
** \details deals with whitespace
** \details converts using multiplication by 10, adding value,
** \details subtracting ascii for '0'
*/
int	ft_atoi(const char *str)
{
	int	notation;
	int	total;
	int	i;

	i = 0;
	notation = 1;
	total = 0;
	while (helper_isspace(str[i]))
		i++;
	if (isprefix(str[i]) && isprefix(str[i + 1]))
		return (0);
	if (str[i] == '-')
		notation = -1;
	if (isprefix(str[i]))
		i++;
	while (ft_isdigit(str[i]))
	{
		convert_to_int(str[i], &total);
		i++;
	}
	return (total * notation);
}
