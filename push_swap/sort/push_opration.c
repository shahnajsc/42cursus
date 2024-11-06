/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_opration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:12:16 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/03 14:35:53 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rarb(t_pswap *psp)
{
	while (psp->cost_a > 0 && psp->cost_b > 0)
	{
		rr(psp);
		psp->cost_a--;
		psp->cost_b--;
	}
	while (psp->cost_a > 0)
	{
		ra(psp);
		psp->cost_a--;
	}
	while (psp->cost_b > 0)
	{
		rb(psp);
		psp->cost_b--;
	}
}

void	op_rrarrb(t_pswap *psp)
{
	while (psp->cost_a > 0 && psp->cost_b > 0)
	{
		rrr(psp);
		psp->cost_a--;
		psp->cost_b--;
	}
	while (psp->cost_a > 0)
	{
		rra(psp);
		psp->cost_a--;
	}
	while (psp->cost_b > 0)
	{
		rrb(psp);
		psp->cost_b--;
	}
}

void	op_rarrb(t_pswap *psp)
{
	while (psp->cost_a > 0)
	{
		ra(psp);
		psp->cost_a--;
	}
	while (psp->cost_b > 0)
	{
		rrb(psp);
		psp->cost_b--;
	}
}

void	op_rrarb(t_pswap *psp)
{
	while (psp->cost_a > 0)
	{
		rra(psp);
		psp->cost_a--;
	}
	while (psp->cost_b > 0)
	{
		rb(psp);
		psp->cost_b--;
	}
}
