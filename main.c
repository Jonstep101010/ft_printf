/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:30 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/26 12:09:02 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// ft_printf(" %x ", LONG_MAX);
	// int	val = 0;
	printf("\nreturn value own: %d\n", ft_printf("own function: %x", LONG_MAX));
	printf("return value org: %d", printf("\norg function: %x\n", LONG_MAX));
	printf("\n- - - - - - - - - - \n");
	// val = INT_MIN;
	// val = LONG_MAX;
	// val = LONG_MIN;
	// val = ULONG_MAX;
	// val = -42;
	// ft_printf("Hello: %c", 'c');
	// printf("\nReturn Value of ft_printf 1: %d\n", ft_printf("%%\n"));
	// char	*str;
	// int		d;

	// d = INT_MAX;
	// printf("\nReturn of ft_printf: %d\n", ft_printf("%d", d));
	// printf("\nReturn of org: %d\n", printf("%d", d));
	// for ()
	// int	d = -4;
	// while (d++ < 13)
	// {
	// 	printf("\norg return: %d\n", printf("\nPrint unsigned org: %u\n", d));
	// 	printf("\nown return: %d\n", ft_printf("\nPrint unsigned own: %u\n", d));
	// 	printf("- - - - - - - - - - - - -\n");
	// }
	// char str[] = "sanoj";
	// s_reverse(str);
	// printf("%s", str);
	// put_hex((size_t)str);
	// printf("\n%p", &str);
	// ft_printf("%u", -200000);
	// ft_printf("%u", -6000023);
	// str = "Hello, World";
	// printf("\nReturn of original Printf 2: %d\n", printf("org: %s", str));
	// printf("\nReturn of ft_printf: %d\n", ft_printf("own: %s", str));
	// ft_putstr_fd(str, 1);
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
