/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:59:31 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/06 10:55:48 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	opreation_execute(t_pswap *psp, char *operation)
{
	if (!ft_strcmp(operation, "sa\n"))
		sa(psp);
	else if (!ft_strcmp(operation, "pa\n"))
		pa(psp);
	else if (!ft_strcmp(operation, "ra\n"))
		ra(psp);
	else if (!ft_strcmp(operation, "rra\n"))
		rra(psp);
	else if (!ft_strcmp(operation, "sb\n"))
		sb(psp);
	else if (!ft_strcmp(operation, "pb\n"))
		pb(psp);
	else if (!ft_strcmp(operation, "rb\n"))
		rb(psp);
	else if (!ft_strcmp(operation, "rrb\n"))
		rrb(psp);
	else if (!ft_strcmp(operation, "ss\n"))
		ss(psp);
	else if (!ft_strcmp(operation, "rr\n"))
		rr(psp);
	else if (!ft_strcmp(operation, "rrr\n"))
		rrr(psp);
	else
		return (operation_error());
	return (0);
}

int	checker(t_pswap *psp)
{
	char	*line;

	line = reader(line, BUFFER_SIZE, 0);
	while (line)
	{
		if (opreation_execute(psp, line))
		{
			free(line);
			free_stack(psp->a);
			free_stack(psp->b);
			return (1);
		}
		free(line);
		line = reader(line, BUFFER_SIZE, 0);
	}
	free(line);
	return (0);
}
