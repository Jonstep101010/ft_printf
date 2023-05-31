/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:40:44 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/20 19:11:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** @brief concatenates two strings, terminate (if free byte in dst)
** @param dst pointer to string
** @param src pointer to string
** @param dstsize size of destination buffer
** @return initial length of dst + lenght of src (without termination)
** @details both src and dst need to be null-terminated
** \details if whole string traversed without finding '\0',
** \details length of string is considered to be size,
** \details dst will not be terminated, since there was no space
** \details (check to prevent problems in incorrect code (overflow))
** \details srclen/dstlen: lenght for src and dst (not dstsize)
** \details accounts for dstsize being 0, or smaller than the length
** \details copies as long as src is & dstsize - 1 is respected
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	srclen = ft_strlen(src);
	i = -1;
	while ((++i < srclen) && (i + dstlen < dstsize - 1))
	{
		dst[i + dstlen] = src[i];
	}
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}
