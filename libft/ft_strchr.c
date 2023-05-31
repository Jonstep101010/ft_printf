/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:51:00 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/27 23:27:23 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
/// @brief search string for character (starts with first)
/// @param str string to search
/// @param c character to find
/// @return pointer to char c (if found), otherwise 0
/// @details includes termination character in search
*/
char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = (char *) str;
	while (++i <= ft_strlen(str))
		if (ptr[i] == (char) c)
			return (&ptr[i]);
	return (0);
}
