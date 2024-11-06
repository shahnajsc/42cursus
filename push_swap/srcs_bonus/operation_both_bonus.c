/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_both_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:12:25 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/03 22:13:12 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ss(t_pswap *stacks)
{
	if (!stacks)
		return ;
	swap_top(stacks->a);
	swap_top(stacks->b);
}

void	rr(t_pswap *stacks)
{
	if (!stacks)
		return ;
	rotate_up(stacks->a);
	rotate_up(stacks->b);
}

void	rrr(t_pswap *stacks)
{
	if (!stacks)
		return ;
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
}
