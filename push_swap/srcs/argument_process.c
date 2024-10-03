/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:42:11 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/03 16:29:58 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// int	is_int(int nbr)
// {
// 	// is int
// 	// is bigger than int
// }
int	check_duplicate(int *numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		while (numbers[j] != NULL)
		{
			if (numbers[i] == numbers[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


int	*get_numbers(char **argv, int len)
{
	int	*numbers;
	int i;

	numbers = (int *)malloc(sizeof(int) * (len + 1));
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < len )
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	numbers[i] = NULL;
	if (check_duplicate(numbers))
		error_return(DUP_E);
	return (numbers);
}

t_node	*fill_stack_a(int argc, char **argv)
{
	int	*numbers;
	t_node	*top;
	t_node	*new_node;
	int		i;

	 // error_handle
	i = argc - 1;
	numbers = get_numbers(argv, i);
	top = 0;
	while (i > 0)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->next = top;
		new_node->nbr = numbers[i - 1]; // use get_number
		top = new_node;
		i--;
	}
	return (top);
}
