/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:56:20 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/08 12:00:00 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{

}
/*
    - Deletes and frees the given node and every successor of that node.
    - Using the function ’del’ and 'free(3)'.
    - Finally, the pointer to the list must be set to NULL.
    - 'lst' The address of a pointer to a node.
    - 'del' The address of the function used to delete the content of the node.
*/