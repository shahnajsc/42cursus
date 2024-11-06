/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:39:05 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/06 11:01:51 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_count_a(t_pswap *psp, int nbr)
{
	t_node	*temp_a;
	int		rotate_a;

	temp_a = (*psp->a);
	rotate_a = 0;
	while (temp_a != NULL)
	{
		if (temp_a->nbr == nbr)
		{
			rotate_a = temp_a->position;
			break ;
		}
		temp_a = temp_a->next;
	}
	return (rotate_a);
}

int	push_rotate_b(t_pswap *psp, int nbr)
{
	int		rotate_b;
	t_node	*temp_b;
	t_node	*temp_next;

	temp_b = *(psp->b);
	rotate_b = 1;
	if (nbr > temp_b->nbr && nbr < get_tail_node(&temp_b)->nbr)
		rotate_b = 0;
	else if (nbr > max_value(&temp_b) || nbr < min_value(&temp_b))
		rotate_b = get_position_a(&temp_b, max_value(&temp_b));
	else
	{
		temp_next = temp_b->next;
		while ((temp_b->nbr < nbr || temp_next->nbr > nbr))
		{
			temp_b = temp_b->next;
			temp_next = temp_b->next;
			rotate_b++;
		}
	}
	return (rotate_b);
}

void	push_cost_to_b(t_pswap *psp, int nbr)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = rotate_count_a(psp, nbr);
	rotate_b = push_rotate_b(psp, nbr);
	if (rotate_a < median(psp->a) && rotate_b < median(psp->b))
	{
		psp->rotate_flag = 1;
		psp->total_cost = cost_rarb(psp, rotate_a, rotate_b);
	}
	else if (rotate_a >= median(psp->a) && rotate_b >= median(psp->b))
	{
		psp->rotate_flag = 2;
		psp->total_cost = cost_rrarrb(psp, rotate_a, rotate_b);
	}
	else if (rotate_a < median(psp->a) && rotate_b >= median(psp->b))
	{
		psp->rotate_flag = 3;
		psp->total_cost = cost_rarrb(psp, rotate_a, rotate_b);
	}
	else if (rotate_a >= median(psp->a) && rotate_b < median(psp->b))
	{
		psp->rotate_flag = 4;
		psp->total_cost = cost_rrarb(psp, rotate_a, rotate_b);
	}
}

void	set_cheapest_cost_b(t_pswap *psp)
{
	t_node	*temp_a;
	int		lowest_cost;
	int		cost_a;
	int		cost_b;
	int		flag;

	lowest_cost = INT_MAX;
	temp_a = *(psp->a);
	while (temp_a != NULL)
	{
		push_cost_to_b(psp, temp_a->nbr);
		if (psp->total_cost < lowest_cost)
		{
			lowest_cost = psp->total_cost;
			cost_a = psp->cost_a;
			cost_b = psp->cost_b;
			flag = psp->rotate_flag;
		}
		temp_a = temp_a->next;
	}
	psp->cost_a = cost_a;
	psp->cost_b = cost_b;
	psp->rotate_flag = flag;
}

void	push_to_b(t_pswap *psp)
{
	while (stack_length(psp->a) > 3 && !is_sorted(psp->a))
	{
		set_position(psp->a);
		set_cheapest_cost_b(psp);
		if (psp->rotate_flag == 1)
			op_rarb(psp);
		else if (psp->rotate_flag == 2)
			op_rrarrb(psp);
		else if (psp->rotate_flag == 3)
			op_rarrb(psp);
		else if (psp->rotate_flag == 4)
			op_rrarb(psp);
		pb(psp);
	}
	set_position(psp->b);
	if (!is_sorted(psp->a))
		sort_three(psp);
}
