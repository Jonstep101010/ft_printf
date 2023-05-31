/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:08:28 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/20 21:02:01 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

/*
** @brief adds node new at end of list
** @param lst &pointer to first lik of a list
** @param new &pointer for node to add
** @details calls ft_lstlast for finding last value
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
	}
	else
		ft_lstlast(*lst)-> next = new;
}
