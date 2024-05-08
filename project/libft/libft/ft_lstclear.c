/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:56:20 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/08 14:01:12 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
/*
static void	ft_del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	list1 = ft_lstnew(ft_strdup("abcde"));
	list2 = ft_lstnew(ft_strdup("12345"));
	list3 = ft_lstnew(ft_strdup("!@#$"));
	list1->next = list2;
	list2->next = list3;

	ft_lstclear(&list1, &ft_del);
}
*/
/*
    - Deletes and frees the given node and every successor of that node.
    - Using the function ’del’ and 'free(3)'.
    - Finally, the pointer to the list must be set to NULL.
    - 'lst' The address of a pointer to a node.
    - 'del' The address of the function used to delete the content of the node.
*/