/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:29:38 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/07 15:07:04 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int count;

    count = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        count++;
    }
    return (count);
}
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

int main(void)
{
    t_list *lst_1 = ft_lstnew("Hello");
    t_list *lst_2 = ft_lstnew("world");
    printf("list length: %d\n", ft_lstsize(lst_1));
    ft_lstadd_front(&lst_2, lst_1);
    printf("list length: %d\n", ft_lstsize(lst_2));
    
}*/
/*
    - Counts the number of nodes in the list 'lst'.
    - 'lst' is the beginning of the list.
    - Return the length of the list.
*/