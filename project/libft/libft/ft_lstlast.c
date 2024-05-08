/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:20:22 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/08 09:35:16 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
	while (lst != NULL)
	{
        if (lst->next == NULL)
            return (lst);
        else
		    lst = lst->next;
	}
	return (lst);
}
/*
- Returns the last node of the list 'lst'.
- 'lst' The beginning of the list
*/