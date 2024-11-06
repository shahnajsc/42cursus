/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:10:20 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 15:30:48 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	sa(t_pswap *stacks)
{
	if (!stacks)
		return ;
	swap_top(stacks->a);
}

void	pa(t_pswap *stacks)
{
	if (!stacks)
		return ;
	push_top(stacks->a, stacks->b);
}

void	ra(t_pswap *stacks)
{
	if (!stacks)
		return ;
	rotate_up(stacks->a);
}

void	rra(t_pswap *stacks)
{
	if (!stacks)
		return ;
	reverse_rotate(stacks->a);
}
