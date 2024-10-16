/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:59:25 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/11 15:08:41 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_grid(void **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	error_arguments(char **args_nbr, int argc)
{
	ft_putstr_fd("Error\n", 2);
	if (argc == 2)
		free_grid((void *)args_nbr);
	exit(1);
}

void	free_stack(t_node **stack)
{
	t_node *temp_node;

	if (!stack || !(*stack))
		return ;
	while (*stack != NULL)
    {
        temp_node = *stack;
        *stack = (*stack)->next;
        free(temp_node); // Free the current node
    }
	*stack = NULL;
}
