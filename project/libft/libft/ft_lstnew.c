/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:04:14 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/07 10:50:43 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>

int main(void)
{
    t_list *new_1 = ft_lstnew("Hello, World!");
    printf("%s\n", (char *)new_1->content);

    t_list *new_2 = ft_lstnew(NULL);
    printf("%s\n", (char *)new_2->content);

    t_list *new_3 = ft_lstnew("123478");
    printf("%s\n", (char *)new_3->content);
}
*/
