/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:38:48 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/08 10:01:41 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
	{
		*lst = new;
	}
	while (lst != NULL)
	{
		if ((*lst)->next == NULL)
		{
			(*lst)->next = new;
			new->next = NULL;
		}
	}
}
/*
    - Adds the node ’new’ at the end of the list.
    - Lst:  The address of a pointer to the first link of a list.
    - 'new' The address of a pointer to the node to be added to the list.
*/
