/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:11:55 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/04 11:34:48 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	cost_rarb(t_pswap *psp, int rotate_a, int rotate_b)
{
	int	total_cost;
	int	cost_a;
	int	cost_b;

	cost_a = rotate_a;
	cost_b = rotate_b;
	psp->cost_a = cost_a;
	psp->cost_b = cost_b;
	total_cost = 0;
	while (cost_a-- > 0 && cost_b-- > 0)
		total_cost++;
	while (cost_a-- > 0)
		total_cost++;
	while (cost_b-- > 0)
		total_cost++;
	return (total_cost);
}

int	cost_rrarrb(t_pswap *psp, int rotate_a, int rotate_b)
{
	int	total_cost;
	int	cost_a;
	int	cost_b;

	cost_a = stack_length(psp->a) - rotate_a;
	cost_b = stack_length(psp->b) - rotate_b;
	psp->cost_a = cost_a;
	psp->cost_b = cost_b;
	total_cost = 0;
	while (cost_a-- > 0 && cost_b-- > 0)
		total_cost++;
	while (cost_a-- > 0)
		total_cost++;
	while (cost_b-- > 0)
		total_cost++;
	return (total_cost);
}

int	cost_rarrb(t_pswap *psp, int rotate_a, int rotate_b)
{
	int	total_cost;
	int	cost_a;
	int	cost_b;

	cost_a = rotate_a;
	cost_b = stack_length(psp->b) - rotate_b;
	psp->cost_a = cost_a;
	psp->cost_b = cost_b;
	total_cost = 0;
	while (cost_a-- > 0)
		total_cost++;
	while (cost_b-- > 0)
		total_cost++;
	return (total_cost);
}

int	cost_rrarb(t_pswap *psp, int rotate_a, int rotate_b)
{
	int	total_cost;
	int	cost_a;
	int	cost_b;

	cost_a = stack_length(psp->a) - rotate_a;
	cost_b = rotate_b;
	psp->cost_a = cost_a;
	psp->cost_b = cost_b;
	total_cost = 0;
	while (cost_a-- > 0)
		total_cost++;
	while (cost_b-- > 0)
		total_cost++;
	return (total_cost);
}
