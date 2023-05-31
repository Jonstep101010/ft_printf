/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:01:55 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/27 20:04:13 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief copies n bytes from one memory location to another
** @param dst pointer to dst memory location
** @param src pointer to src memory location
** @param n bytes to copy
** @return value of dst
** @details possible if pointers overlap (no tmp array due to restrictions)
** \details casts ptrsrc then copies to casted ptrdst
*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*ptrdst;
	char			*ptrsrc;

	ptrdst = (char *) dst;
	ptrsrc = (char *) src;
	if (!dst && !src)
		return (NULL);
	while (dst >= src && n > 0 && n-- >= 0)
		ptrdst[n] = ptrsrc[n];
	while (n--)
		*ptrdst++ = *ptrsrc++;
	return (dst);
}
