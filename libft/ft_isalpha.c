/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:01:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/02 19:23:41 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief checks if given value is alphabetic (ascii table)
** @param c value of input character
** @return 1 if true, 0 if not
*/
int	ft_isalpha(int c)
{
	if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
		return (1);
	return (0);
}
