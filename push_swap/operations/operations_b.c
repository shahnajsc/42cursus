/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:02:21 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/14 17:49:23 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	swap_top(stacks->b);
	ft_putstr_fd("sb\n", 1);
}

void	pb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	push_top(stacks->b, stacks->a);
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	rotate_up(stacks->b);
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	reverse_rotate(stacks->b);
	ft_putstr_fd("rrb\n", 1);
}
