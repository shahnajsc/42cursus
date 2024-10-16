/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:07:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/11 17:29:08 by shachowd         ###   ########.fr       */
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
	p_swap->length = stack_length(a);
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
	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_a =  fill_stack_a(argc, ++argv, stack_a);
	init_p_swap(&p_swap, stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort_stack(&p_swap);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	//***** for test ****////
// 	t_node **stack_a;
// 	t_node **stack_b;

// 	if (argc == 1) // one av input or multi input???
// 	{
// 		exit(1); // code 1 or 0?
// 	}
// 	stack_a = (t_node **)malloc(sizeof(t_node));
// 	stack_b = (t_node **)malloc(sizeof(t_node));
// 	*stack_a = NULL;
// 	*stack_b = NULL;
// 	stack_a =  fill_stack_a(argc, argv, stack_a);
// 	if (!stack_a)
// 		printf("error from main ");
// 	display_stack(stack_a);
// 	printf("\n");
// 	rotate_up(stack_a);
// 	display_stack(stack_a);
// 	printf("\n");
// 	printf("\n");
// 	printf("\n");
// 	stack_b =  fill_stack_b(argc, argv, stack_b);
// 	if (!stack_b)
// 		printf("error from main ");

// 	display_stack(stack_b);
// 	printf("\n");
// 	reverse_rotate(stack_b);
// 	display_stack(stack_b);
// 	printf("\n");
// 	swap_top(stack_b);
// 	display_stack(stack_b);
// 	printf("\n");
// 	push_top(stack_b, stack_a);
// 	display_stack(stack_b);
// 	printf("\n");
// 	display_stack(stack_a);
// 	printf("\n");
// 	free_stack(stack_b);

// }
