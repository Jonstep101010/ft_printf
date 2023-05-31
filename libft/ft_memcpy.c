/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:36:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/11 23:08:40 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief copies data from src pointer to dst pointer
** @param dst pointer  to array
** @param src pointer to source
** @param n bytes to copy
** @return returns pointer to dst if successful, otherwise NULL
** @details uses type casting to make comparison possible
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s = src;

	d = dst;
	if (!d && !s)
		return (0);
	while (n-- && (d || s))
		*d++ = *s++;
	return (dst);
}
