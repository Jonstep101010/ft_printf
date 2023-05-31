/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:28:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/02 20:03:52 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief compare strings
** @param s1 first string to compare
** @param s2 second string to compare
** @param n maximum characters to compare
** @return s1 less, greater or equal s2
** @details compares at most the first n bytes of s1 and s2
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	while (n-- > 0)
	{
		ps1 = (unsigned char *) s1++;
		ps2 = (unsigned char *) s2++;
		if (!((*ps1) || (*ps2)))
			return (0);
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
	}
	return (0);
}
