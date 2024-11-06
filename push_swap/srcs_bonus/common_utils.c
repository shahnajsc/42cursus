/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:59:54 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 15:32:34 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
