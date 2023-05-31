/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:24:13 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/19 21:42:24 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief duplicate a string through memory allocation
** @param s source string to copy
** @return pointer to copied string
** @details strlen, malloc used, guard for NULL,
** \details termination character and cast for return
*/
char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	size;

	size = ft_strlen(s) + 1;
	copy = malloc(size);
	if (!copy)
		return (0);
	ft_memcpy(copy, s, size);
	return (copy);
}

/*alternative without ft_memcpy*/
/* char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	size += 1;
	copy = malloc(size);
	if (!copy)
		return (0);
	while (size-- && (copy))
		copy[size] = s[size];
	return (copy);
} */
