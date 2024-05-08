/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:16:37 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/08 11:45:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);

}

static void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;

	list = ft_lstnew(ft_strdup("abcde"));
	ft_lstdelone(list, &del);
}
/*
    - Takes as a parameter an elem and frees the memory of the elem’s content
    - Using the function ’del’ given as a parameter and free the elem.
    - The memory of ’next’ must not be freed.
*/