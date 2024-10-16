/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:47:50 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/10 17:35:55 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_top(t_node **stack)
{
	// top and 2nd
	t_node *top;
	t_node *third_node;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	top = (*stack)->next;
	if (top->next != NULL)
	{
		third_node = top->next;
		third_node->prev = *stack;
	}
	(*stack)->prev = top;
	(*stack)->next = top->next;
	top->next = *stack;
	top->prev = NULL;
	*stack = top;
}

void	push_top(t_node **stack_to, t_node **stack_from)
{
	t_node *node_to_push;

	if (!stack_to || !stack_from || *stack_from == NULL)
		return ;
	node_to_push = create_new_node((*stack_from)->nbr);
	add_node_top(stack_to, node_to_push);
	delete_node_top(stack_from);
}

void	rotate_up(t_node **stack)
{
	// top become bottom (2nd element become top)
	t_node *top;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	add_node_bottom(stack, top);

}

void	reverse_rotate(t_node **stack)
{
	// bottom become top (top become 2nd element)
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
	bottom->prev = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}

// void	push_top2(t_node **stack_to, t_node **stack_from)
// {
// t_node *node_to_push;

// 	if (!stack_to || !stack_from || *stack_from == NULL)
// 		return ;
// 	node_to_push = *stack_from;
// 	*stack_from = (*stack_from)->next;
// 	if ((*stack_from) != NULL)
// 		(*stack_from)->prev = NULL;
// 	if (*stack_to == NULL)
// 	{
// 		node_to_push->next = NULL;
// 		*stack_to = node_to_push;
// 	}
// 	else
// 	{
// 		(*stack_to)->prev = node_to_push;
// 		node_to_push->next = *stack_to;
// 		*stack_to = node_to_push;
// 	}
// }

