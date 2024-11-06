/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:05:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 15:54:57 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort_five(t_pswap *psp)
{
	int	lowest_index;
	int	len;
	int	position;

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

void	final_sort(t_pswap *psp)
{
	t_pswap	*temp_p;
	int		lowest_poiotiion;
	int		lowest_value;

	temp_p = psp;
	set_position(psp->a);
	lowest_value = min_value(psp->a);
	lowest_poiotiion = get_position_a(psp->a, lowest_value);
	if (lowest_poiotiion < stack_length(psp->a) / 2)
	{
		while ((*temp_p->a)->nbr != lowest_value)
			ra(psp);
	}
	else
	{
		while ((*temp_p->a)->nbr != lowest_value)
			rra(psp);
	}
}

void	sort_bigger(t_pswap *psp)
{
	if (!psp)
		return ;
	pb(psp);
	pb(psp);
	push_to_b(psp);
	push_back_to_a(psp);
	final_sort(psp);
}

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
	else if (p_swap->length_a > 5 && p_swap->length_a <= INT_MAX)
		sort_bigger(p_swap);
}
//-4934 9 0 -66 -1 -456 431 11 22 66 87
// printf("f_s A\n");
// 	display_stack(psp->a);
// 	printf("f_S  B\n");
// 	display_stack(psp->b);
// 	printf("\n");
// 	printf("STACK_B\n");
// 	display_stack(psp->b);
