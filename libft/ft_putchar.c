/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:39:54 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/28 19:21:32 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
@brief write a character to stdout
@param c character to write
@return return 1, -1 if write fails
*/
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
