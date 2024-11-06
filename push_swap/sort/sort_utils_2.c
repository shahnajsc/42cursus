/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:16:32 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 15:52:44 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index(char **numbers, int nbr)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (numbers[i] != NULL)
	{
		if (nbr > ft_atoi(numbers[i]))
			index++;
		i++;
	}
	return (index);
}

int	get_position(t_pswap *psp, int lowest_index)
{
	int		position;
	t_node	*temp_a;

	temp_a = *(psp->a);
	while (temp_a != NULL)
	{
		if (lowest_index == temp_a->index)
			position = temp_a->position;
		temp_a = temp_a->next;
	}
	return (position);
}

int	min_value(t_node **stack)
{
	int		lowest_value;
	t_node	*temp;

	temp = *stack;
	lowest_value = temp->nbr;
	while (temp != NULL)
	{
		if (temp->nbr < lowest_value)
			lowest_value = temp->nbr;
		temp = temp->next;
	}
	return (lowest_value);
}

int	max_value(t_node **stack)
{
	int		highest_value;
	t_node	*temp;

	temp = *stack;
	highest_value = temp->nbr;
	while (temp != NULL)
	{
		if (temp->nbr > highest_value)
			highest_value = temp->nbr;
		temp = temp->next;
	}
	return (highest_value);
}

t_node	*get_tail_node(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
