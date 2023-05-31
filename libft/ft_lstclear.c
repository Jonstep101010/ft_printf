/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:46:23 by jschwabe          #+#    #+#             */
/*   Updated: 2023/04/02 20:50:15 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief deletes and frees node and successors
** @param lst &pointer to node
** @param del &function used to delete content
** @details (*lst)->content is pointer, instead of lst->content
** \details needs tmp t_list for storing data before deletion
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if ((!lst) || !*lst)
		return ;
	while (*lst != NULL)
	{
		del((*lst)-> content);
		tmp = (*lst)-> next;
		free(*lst);
		*lst = tmp;
	}
}
