/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:30 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/27 15:15:58 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("\nreturn value own: %d\n", ft_printf("\nown function: %+d\n", 42));
	printf("return value org: %d", printf("\norg function: %+d\n", 42));
	printf("\n- - - - - - - - - - \n");
	ft_printf("Hello: %c", 'c');
	return (0);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello, World!";
// 	ft_printf("%s", str);
// 	printf("\n%s", str);
// 	return (INT_MAX);
// }
