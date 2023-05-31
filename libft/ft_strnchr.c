/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:44:23 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/28 19:20:19 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
@brief returns index of a character within a string
@param s string to search
@param c (int) character to find
@return index of c in s
*/
int	ft_strnchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*(s++) == (char) c)
			return (i);
		i++;
	}
	return (-1);
}
