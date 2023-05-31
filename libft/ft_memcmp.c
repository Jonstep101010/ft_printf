/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:04:38 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/02 20:04:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief compares the values of two pointers
** @param s1 first pointer to compare
** @param s2 second pointer to compare
** @param n bytes to compare
** @details compares elements from two arrays (unsigned char)
** @details beginning at adresses s1 and s2 (size n)
** @details if equal, return 0
** @details if diff s1 to s2 - pos
** @details otherwise - negative
** @return difference
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;

	while (n-- > 0)
	{
		ps1 = (const unsigned char *) s1++;
		ps2 = (const unsigned char *) s2++;
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
	}
	return (0);
}
