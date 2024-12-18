/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:56:25 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/06 10:54:58 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_new_node(int number, int index, int position)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->nbr = number;
	new_node->index = index;
	new_node->position = position;
	return (new_node);
}

void	add_node_top(t_node **top, t_node *new_node)
{
	if (!top || !new_node)
		return ;
	if (*top == NULL)
		*top = new_node;
	else
	{
		new_node->next = *top;
		*top = new_node;
	}
}

void	add_node_bottom(t_node **top, t_node *new_node)
{
	t_node	*temp_node;

	if (!top || !new_node)
		return ;
	if (*top == NULL)
	{
		*top = new_node;
		return ;
	}
	temp_node = *top;
	while (temp_node->next != NULL)
	{
		temp_node = temp_node->next;
	}
	new_node->next = NULL;
	temp_node->next = new_node;
}

void	delete_node_top(t_node **top)
{
	t_node	*temp_node;

	if (!top || *top == NULL)
		return ;
	temp_node = *top;
	if (temp_node->next == NULL)
	{
		free(temp_node);
		*top = NULL;
	}
	else
	{
		*top = temp_node->next;
		free(temp_node);
	}
}
