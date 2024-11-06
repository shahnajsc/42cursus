/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:14:19 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/04 11:39:08 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_length(t_node **stack)
{
	int		len;
	t_node	*temp;

	if (!stack || *stack == NULL)
		return (0);
	temp = *stack;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	is_sorted(t_node **stack_a)
{
	t_node	*temp_a;

	if (!stack_a || *stack_a == NULL)
		return (0);
	temp_a = *stack_a;
	while (temp_a->next != 0)
	{
		if (temp_a->nbr > temp_a->next->nbr)
			return (0);
		temp_a = temp_a->next;
	}
	return (1);
}

void	set_position(t_node **stack)
{
	t_node	*temp_stack;
	int		i;

	i = 0;
	temp_stack = *stack;
	while (temp_stack != NULL)
	{
		temp_stack->position = i;
		i++;
		temp_stack = temp_stack->next;
	}
}

int	get_position_a(t_node **stack, int nbr)
{
	int		position;
	t_node	*temp_a;

	temp_a = *stack;
	position = 0;
	while (nbr != temp_a->nbr)
	{
		position++;
		temp_a = temp_a->next;
	}
	return (position);
}

int	median(t_node **stack)
{
	int	median;

	if (!stack)
		return (0);
	median = stack_length(stack) / 2;
	return (median);
}
