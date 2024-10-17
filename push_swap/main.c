/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:07:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/17 19:26:52 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h>

static void	init_p_swap(t_pswap *p_swap, t_node **a, t_node **b)
{
	if (!a || !b)
		return ;
	p_swap->a = a;
	p_swap->b = b;
	p_swap->length_a = stack_length(a);
}

int main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;
	t_pswap	p_swap;

	if (argc == 1) // one av input or multi input???
	{
		exit(1); // code 1 or 0?
	}
	stack_a = (t_node **)malloc(sizeof(t_node)); // leaks happen when 1 argument and string ""
	stack_b = (t_node **)malloc(sizeof(t_node)); // leaks happen when 1 argument and string ""
	*stack_a = NULL;
	*stack_b = NULL;
	stack_a =  fill_stack_a(argc, ++argv, stack_a);
	//display_stack(stack_a);
	init_p_swap(&p_swap, stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort_stack(&p_swap);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
