/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:49:21 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/27 20:08:49 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief output int n to file descriptor
** @param n int to output
** @param fd file descriptor on which to write
*/
void	ft_putnbr_fd(int n, int fd)
{
	char	*nbrs;

	nbrs = "0123456789";
	if (n == -2147483648)
	{
		return (ft_putstr_fd("-2147483648", fd));
	}
	if (n < 0)
	{
		ft_putstr_fd("-", fd);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		write(fd, nbrs + n, 1);
}
