/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:47:55 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/20 19:01:03 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** @brief copy src to dst of size
** @param dst pointer to string
** @param src pointer to string
** @param size size of destination buffer
** @return length of src, if return > size, terminate dst
** @details at most copy size-1
** \details terminates unless size == 0 
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	x;

	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	x = -1;
	while ((src[++x] != '\0') && (x < size - 1))
	{
		dst[x] = src[x];
	}
	if (!src[x] || (x == size - 1))
		dst[x] = 0;
	return (srclen);
}
