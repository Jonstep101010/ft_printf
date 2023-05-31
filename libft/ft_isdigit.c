/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:31:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/03/17 18:31:43 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief checks if given value is a digit
** @param c value of character
** @return 1 if true, 0 if not
*/
int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (1);
	return (0);
}
