/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:04:38 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/11 23:07:56 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief places n zero-valued bytes in memory area (*s)
** @param s pointer to memory
** @param n number of bytes to place
** @details works without typecasting
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i++] = 0;
	}
} */
