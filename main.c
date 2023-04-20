/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:30 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/20 17:04:06 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello: %c", "c");
	return (0);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello, World!";
// 	ft_printf("%s", str);
// 	printf("\n%s", str);
// 	return (0);
// }
