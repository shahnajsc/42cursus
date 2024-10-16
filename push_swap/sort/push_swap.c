/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:05:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/15 10:04:11 by shachowd         ###   ########.fr       */
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

void	sort_five(t_pswap *psp)
{
	int	len;
	int	forth_n;
	int	fifth_n;

	len = psp->length;
	while (len > 3)
	{
		pb(psp);
		len--;
	}
	// display_stack(psp->a);
	// display_stack(psp->b);
	forth_n = (*psp->b)->nbr;
	fifth_n = (*psp->b)->next->nbr;
	sort_three(psp);
	//display_stack(psp->a);
	if ((forth_n < (*psp->a)->nbr) && (fifth_n < (*psp->a)->nbr))
	{
		if (forth_n < fifth_n)
			sb(psp);
		pa(psp);
		pa(psp);
	}
	if ((forth_n > (*psp->a)->next->next->nbr) && (fifth_n > (*psp->a)->next->next->nbr))
	{
		if (forth_n < fifth_n)
			sb(psp);
		pa(psp);
		pa(psp);
		ra(psp);
		ra(psp);
	}
	else if ((forth_n < (*psp->a)->nbr) && (fifth_n > (*psp->a)->next->next->nbr))
	{
		pa(psp);
		pa(psp);
		ra(psp);
	}
	else if ((forth_n > (*psp->a)->nbr) && (fifth_n > (*psp->a)->next->next->nbr))
	{
		pa(psp);
		pa(psp);
		ra(psp);
	}


}

// void	sort_turk(t_pswap *stacks)
// {

// }

void	sort_stack(t_pswap *p_swap)
{
	if (!p_swap)
		return ;
	if (p_swap->length == 2 && (*p_swap->a)->nbr > (*p_swap->a)->next->nbr)
		sa(p_swap);
	else if (p_swap->length == 3)
		sort_three(p_swap);
	else if (p_swap->length > 3 && p_swap->length <= 5)
		sort_five(p_swap);
	// else
	// 	ft_putstr_fd("Error\n", 2);
}


// static void	sort_stack(t_pushswap *ps)
// {
// 	if (ps->a->size == 2 && ps->a->head->value > ps->a->head->previous->value)
// 		sa(ps);
// 	else if (ps->a->size == 3)
// 		sort_three(ps);
// 	else if (ps->a->size <= 5)
// 		sort_five(ps);
// 	else
// 	{
// 		push_a2b(ps, ps->a->size);
// 		push_b2a(ps, ps->b->size);
// 	}
// }
