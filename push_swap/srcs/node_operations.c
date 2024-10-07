/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:46:03 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/04 16:57:03 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*add_new_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->nbr = number;
	return (new_node);
}

void	add_node_front(t_node **top, t_node *new_node)
{
	if (!top || !new_node)
		return ;
	new_node->next = *top;
	*top = new_node;
}
