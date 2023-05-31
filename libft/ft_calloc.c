/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:03:34 by jschwabe          #+#   #+#            */
/*   Updated: 2023/04/03 12:53:21 by jschwabe         ###  ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** @brief allocates and points to memory
** @param nitems number of elements to allocate
** @param size size of elements
** @return pointer to allocated memory, NULL if failure (1, for byte possible)
** @details ptr for memory space, iterating through and initializing,
** \details allocate using malloc, guarding for ptr being 0,
*/
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems && (nitems * size) / nitems != size)
		return (NULL);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	return ((ft_memset(ptr, 0, nitems * size)));
}
