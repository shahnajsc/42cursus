/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:14:19 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/17 19:36:39 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	stack_length(t_node **stack)
{
	int	len;
	t_node *temp;

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
	t_node *temp_a;

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
