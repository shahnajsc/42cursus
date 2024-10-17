/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:05:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/17 19:25:39 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	sort_three(t_pswap *psp)
{
	int	first_n;
	int	second_n;
	int	third_n;

	first_n = (*psp->a)->nbr;
	second_n = (*psp->a)->next->nbr;
	third_n = (*psp->a)->next->next->nbr;
	if (second_n > third_n && third_n > first_n)
	{
		sa(psp);
		ra(psp);
	}
	else if (second_n > first_n && first_n > third_n)
		rra(psp);
	else if (third_n > first_n && first_n > second_n)
		sa(psp);
	else if (first_n > third_n && third_n > second_n)
		ra(psp);
	else if (first_n > second_n && second_n > third_n)
	{
		sa(psp);
		rra(psp);
	}
}

int	get_position(t_pswap *psp, int lowest_index)
{
	int	position;
	t_node *temp_a;

	temp_a = *(psp->a);
	while (temp_a != NULL)
	{
		if (lowest_index == temp_a->index)
			position = temp_a->position;
		temp_a = temp_a->next;
	}
	return (position);
}

void	sort_five(t_pswap *psp)
{
	int	lowest_index;
	int	len;
	int position;

	len = psp->length_a;
	lowest_index = 0;
	while (len > 3)
	{
		position = get_position(psp, lowest_index);
		if ((*psp->a)->index != lowest_index)
		{
			if (position <= len / 2)
				while ((*psp->a)->index != lowest_index)
					ra(psp);
			else
				while ((*psp->a)->index != lowest_index)
					rra(psp);
		}
		pb(psp);
		lowest_index++;
		len--;
	}
	sort_three(psp);
	pa(psp);
	pa(psp);
}

// void	sort_turk(t_pswap *stacks)
// {

// }

void	sort_stack(t_pswap *p_swap)
{
	if (!p_swap)
		return ;
	if (p_swap->length_a == 2 && (*p_swap->a)->nbr > (*p_swap->a)->next->nbr)
		sa(p_swap);
	else if (p_swap->length_a == 3)
		sort_three(p_swap);
	else if (p_swap->length_a > 3 && p_swap->length_a <= 5)
		sort_five(p_swap);
	// else
	// 	ft_putstr_fd("Error\n", 2);
}

