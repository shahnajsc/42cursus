/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:59:25 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/07 17:09:59 by shachowd         ###   ########.fr       */
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

void error_return(t_error err_type)
{
	ft_putstr_fd("Error\n", 2);
	if (err_type == DUP_E)
		ft_putstr_fd("there are duplicates", 2);
	if (err_type == IS_INT_E)
		ft_putstr_fd("some arguments aren’t integers", 2);
	if (err_type == BIG_INT_E)
		ft_putstr_fd("some arguments are bigger than an integer", 2);
	exit(0);
}

void	free_stack(t_node **stack)
{
	t_node *temp_node;

    if (!stack)
		return ;
	while (*stack != NULL)
    {
        temp_node = *stack;
        *stack = (*stack)->next;
        free(temp_node); // Free the current node
    }
	*stack = NULL;
}
