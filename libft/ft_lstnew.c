/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:10:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/05/20 20:47:37 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief allocate with malloc - content initialized with its value
** @param content to create node with
** @return new node, NULL if failure
** @details next is initialized to NULL
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc((sizeof(t_list)));
	if (new_node)
	{
		new_node -> content = content;
		new_node -> next = NULL;
		return (new_node);
	}
	return (NULL);
}
