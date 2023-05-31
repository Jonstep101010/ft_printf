/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:01:42 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/20 19:01:49 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief return substring for string - allocate memory
** @param s string from which to create substring
** @param start start index of substring in s
** @param len maximum length of substring
** @return substring, NULL if allocation fails
** @details check if string is empty, set length of string
** \details guard against index start being greater than length -
** \details return "" (size 1); check len against size - index (substr)
** \details if so: set len to them; allocate with malloc(len+1)
** \details check for empty substr; set to values in string for <len
** \details terminate & return
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	len += 1;
	substr = (char *) malloc(len);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len);
	ft_strlcat(substr, "", len);
	return (substr);
}

/*alternative without calls to ft_strlc...*/
/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	substr = (char *) malloc(len + 1);
	if (!substr)
		return (NULL);
	i = -1;
	start -= 1;
	while (++i < len && ++start < slen)
		substr[i] = s[start];
	substr[len] = '\0';
	return (substr);
} */
