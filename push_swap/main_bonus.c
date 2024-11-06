/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:51:04 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 15:46:39 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	init_p_swap(t_pswap *psp, t_node **a, t_node **b)
{
	if (!a || !b)
		return ;
	psp->a = a;
	psp->b = b;
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_pswap	psp;

	if (argc < 2)
	{
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = fill_stack_a(argc, ++argv, &stack_a);
	init_p_swap(&psp, &stack_a, &stack_b);
	if (checker(&psp))
		return (1);
	if (is_sorted(&stack_a) && stack_length(&stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
