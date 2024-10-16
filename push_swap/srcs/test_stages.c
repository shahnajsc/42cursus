/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:52:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/07 17:11:15 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/push_swap.h"
#include <stdio.h>

void display_stack(t_node **stack_a)
{
	//t_node *top;
	t_node *temp_node;

	if (stack_a == NULL || *stack_a == NULL)
	{
		printf("stack is empty\n");
		exit(1);
	}
	temp_node = *stack_a;
	while (temp_node != NULL)
	{
		printf("index add : [%p] : %d\n", (void *)temp_node, temp_node->nbr);
		temp_node = temp_node->next;
	}
	free(stack_a);
}
