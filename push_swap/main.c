/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:07:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/06 11:01:05 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	init_p_swap(t_pswap *psp, t_node **a, t_node **b)
{
	if (!a || !b)
		return ;
	psp->a = a;
	psp->b = b;
	psp->cost_a = 0;
	psp->cost_b = 0;
	psp->rotate_flag = 0;
	psp->total_cost = 0;
	psp->length_a = stack_length(a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_pswap	p_swap;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
	{
		if (argc == 2 && argv[1][0] == '\0')
			ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = fill_stack_a(argc, ++argv, &stack_a);
	init_p_swap(&p_swap, &stack_a, &stack_b);
	if (!is_sorted(&stack_a))
		sort_stack(&p_swap);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
