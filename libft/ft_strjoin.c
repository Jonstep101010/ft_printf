/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:28:24 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/20 19:30:01 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief allocates and returns new string, concatenation s1 and s2
** @param s1 prefix string
** @param s2 suffix string
** @return new string, NULL if allocation fails
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcat;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strcat = malloc(s1_len + s2_len + 1);
	if (!strcat)
		return (NULL);
	ft_strlcpy(strcat, s1, s1_len + 1);
	return (ft_strlcat(strcat, s2, s1_len + s2_len + 1), strcat);
}

/*implementation without ft_strlcpy/ft_strlcat*/
/* char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	char	*p;

	copy = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy || !s1 || !s2)
		return (NULL);
	p = copy;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	return (*p = '\0', copy);
} */
