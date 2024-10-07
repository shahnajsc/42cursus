/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:52:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/04 17:05:04 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/push_swap.h"
#include <stdio.h>

void display_stack(t_node *stack_a)
{
	//t_node *top;
	t_node *temp_node;

	if (stack_a == 0)
	{
		printf("stack is empty\n");
		exit(1);
	}
	temp_node = stack_a;
	while (temp_node != 0)
	{
		printf("index add : [%p] : %d\n", temp_node, temp_node->nbr);
		temp_node = temp_node->next;
	}
	//free(stack_a);
}
