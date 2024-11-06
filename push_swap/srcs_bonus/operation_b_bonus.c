/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:11:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 15:31:07 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	sb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	swap_top(stacks->b);
}

void	pb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	push_top(stacks->b, stacks->a);
}

void	rb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	rotate_up(stacks->b);
}

void	rrb(t_pswap *stacks)
{
	if (!stacks)
		return ;
	reverse_rotate(stacks->b);
}
