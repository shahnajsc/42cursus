/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:38:48 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/08 11:12:09 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}
/*
    - Adds the node ’new’ at the end of the list.
    - Lst:  The address of a pointer to the first link of a list.
    - 'new' The address of a pointer to the node to be added to the list.
*/
/* 
    begin = NULL;
    ft_lstadd_back(&begin, elem);
    ft_lstadd_back(&begin, elem2);
    ft_lstadd_back(&begin, elem3);
    ft_lstadd_back(&begin, elem4);
    while (begin)
    {
        ft_print_result(begin);
        begin = begin->next;
    }

*/
