/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:38:53 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/02 19:26:53 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief checks if given value is an ascii character
** @param c value of character
** @return 1 if true, 0 if not
** @details includes termination character, includes range from 0 to 127
*/
int	ft_isascii(int c)
{
	if ((c >= 0) && (c < 128))
		return (1);
	return (0);
}
