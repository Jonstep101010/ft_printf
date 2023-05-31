/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:49:30 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/02 20:47:22 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** @brief deletes and frees given node and successors
** @param lst node to free
** @param del &function used to delete content
** @details pointer (list) set to NULL
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
		del(lst -> content);
	free(lst);
}
