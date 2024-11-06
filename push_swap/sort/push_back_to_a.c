/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:56:27 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/06 11:01:21 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_count_b(t_pswap *psp, int nbr)
{
	t_node	*temp_b;
	int		rotate_b;

	temp_b = (*psp->b);
	rotate_b = 0;
	while (temp_b != NULL)
	{
		if (temp_b->nbr == nbr)
		{
			rotate_b = temp_b->position;
			break ;
		}
		temp_b = temp_b->next;
	}
	return (rotate_b);
}

int	push_rotate_a(t_pswap *psp, int nbr)
{
	int		rotate_a;
	t_node	*temp_a;
	t_node	*tmp_next;

	temp_a = *(psp->a);
	rotate_a = 1;
	if (nbr < temp_a->nbr && nbr > get_tail_node(&temp_a)->nbr)
		rotate_a = 0;
	else if (nbr > max_value(&temp_a) || nbr < min_value(&temp_a))
		rotate_a = get_position_a(&temp_a, min_value(&temp_a));
	else
	{
		tmp_next = temp_a->next;
		while (temp_a && tmp_next && (temp_a->nbr > nbr || tmp_next->nbr < nbr))
		{
			temp_a = temp_a->next;
			tmp_next = temp_a->next;
			rotate_a++;
		}
	}
	return (rotate_a);
}

void	push_back_cost_a(t_pswap *psp, int nbr)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = push_rotate_a(psp, nbr);
	rotate_b = rotate_count_b(psp, nbr);
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

void	set_cheapest_cost_a(t_pswap *psp)
{
	t_node	*temp_b;
	int		lowest_cost;
	int		cost_a;
	int		cost_b;
	int		flag;

	lowest_cost = INT_MAX;
	temp_b = *(psp->b);
	while (temp_b != NULL)
	{
		push_back_cost_a(psp, temp_b->nbr);
		if (psp->total_cost < lowest_cost)
		{
			lowest_cost = psp->total_cost;
			cost_a = psp->cost_a;
			cost_b = psp->cost_b;
			flag = psp->rotate_flag;
		}
		temp_b = temp_b->next;
	}
	psp->cost_a = cost_a;
	psp->cost_b = cost_b;
	psp->rotate_flag = flag;
}

void	push_back_to_a(t_pswap *psp)
{
	while (stack_length(psp->b) > 0)
	{
		set_position(psp->b);
		set_cheapest_cost_a(psp);
		if (psp->rotate_flag == 1)
			op_rarb(psp);
		else if (psp->rotate_flag == 2)
			op_rrarrb(psp);
		else if (psp->rotate_flag == 3)
			op_rarrb(psp);
		else if (psp->rotate_flag == 4)
			op_rrarb(psp);
		pa(psp);
	}
	set_position(psp->a);
}
