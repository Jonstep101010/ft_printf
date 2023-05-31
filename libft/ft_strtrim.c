/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:59:32 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/20 21:08:44 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief copies with set removed from beginning and end of string
** @param s string to trim
** @param set reference set of characters to trim
** @return trimmed string, NULL if allocation fails
** @details allocates with malloc, after checking for empty strings;
** \details searching string for set of characters (while for beginning and end)
** \details ft_strlen to iterate from last, substr to cut to variables,
** \details guard for return;
** \details Example: set = "He", s = "HeHello, HeyHe" trim = "llo, Hey"
*/
char	*ft_strtrim(char const *s, char const *set)
{
	char	*trim;
	size_t	slen;

	if (!s)
		return (NULL);
	if (!set)
		return ((char *)s);
	while ((*s) && ft_strchr(set, *s))
		s++;
	slen = ft_strlen(s);
	while ((slen > 0) && ft_strrchr(set, s[slen - 1]))
		slen--;
	trim = ft_substr(s, 0, slen);
	if (!trim)
		return (NULL);
	return (trim);
}
