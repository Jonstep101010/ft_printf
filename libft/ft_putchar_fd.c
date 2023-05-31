/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:26:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/03 14:27:35 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief write to file descriptor
** @param c character to output
** @param fd file descriptor to write on
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
