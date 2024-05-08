/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:24:49 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/08 15:24:57 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
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

int main(void)
{
	t_list *addl =ft_lstnew("world");
    t_list *lst_1 = ft_lstnew("Hello");
    printf("lst_1 content: %s\n", (char *)lst_1->content);

    t_list *new_1 = ft_lstnew("world !");
    printf("new_1 content: %s\n", (char *)new_1->content);

    ft_lstadd_front(&lst_1, new_1);
    printf("after adding new, lst_1 content: %s\n", (char *)lst_1->content);
	int count =0;
	ft_lstadd_front(&addl, lst_1);
	while (addl != NULL)
    {
        addl = addl->next;
		printf("with loop: %s\n", (char *)addl->content);
        count++;
    }
} */
/*
	- Need to add a new node 'new' at the beginning of the list 'lst'
	- lst:  The address of a pointer to the first link of a list.
	- new:  The address of a pointer to the node to be added to the list
*/