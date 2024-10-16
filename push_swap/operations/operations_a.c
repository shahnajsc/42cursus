/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:03:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/11 11:50:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_pswap *stacks)
{
	if (!stacks)
		return ;
	swap_top(stacks->a);
	ft_putstr_fd("sa\n", 1);
}

void	pa(t_pswap *stacks)
{
	if (!stacks)
		return ;
	push_top(stacks->a, stacks->b);
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_pswap *stacks)
{
	if (!stacks)
		return ;
	rotate_up(stacks->a);
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_pswap *stacks)
{
	if (!stacks)
		return ;
	reverse_rotate(stacks->a);
	ft_putstr_fd("rra\n", 1);
}

