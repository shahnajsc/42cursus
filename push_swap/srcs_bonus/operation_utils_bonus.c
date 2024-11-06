/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:16:20 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 16:04:07 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	swap_top(t_node **stack)
{
	t_node	*top;
	t_node	*third_node;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	top = (*stack)->next;
	if (top->next != NULL)
	{
		third_node = top->next;
		(*stack)->next = third_node ;
	}
	else
		(*stack)->next = NULL;
	top->next = *stack;
	*stack = top;
}

void	push_top(t_node **stack_to, t_node **stack_from)
{
	t_node	*node_to_push;

	if (!stack_to || !stack_from || *stack_from == NULL)
		return ;
	node_to_push = create_new_node((*stack_from)->nbr,
			(*stack_from)->index, (*stack_from)->position);
	add_node_top(stack_to, node_to_push);
	delete_node_top(stack_from);
}

void	rotate_up(t_node **stack)
{
	t_node	*top;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	*stack = (*stack)->next;
	add_node_bottom(stack, top);
}

void	reverse_rotate(t_node **stack)
{
	t_node	*bottom;
	t_node	*temp_stack;
	t_node	*last_node;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp_stack = *stack;
	while (temp_stack->next != NULL)
	{
		last_node = temp_stack;
		temp_stack = temp_stack->next;
	}
	last_node->next = NULL;
	bottom = temp_stack;
	bottom->next = *stack;
	*stack = bottom;
}
