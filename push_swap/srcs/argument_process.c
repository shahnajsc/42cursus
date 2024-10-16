/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:42:11 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/07 16:59:42 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	is_integer(char *nbr)
{
	if (!nbr)
		return (0);
	while ((*nbr >= 9 && *nbr <= 13) || (*nbr == 32))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr >= 48 && *nbr <= 57) // do we need to check after the number like -234rt
		return (1);
	return (0);
}

int	check_duplicate(char **args_nbr)
{
	int	i;
	int	j;

	i = 0;
	while (args_nbr[i])
	{
		j = 0;
		while (args_nbr[j])
		{
			if (ft_atoi(args_nbr[i]) == ft_atoi(args_nbr[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**parse_numbers(int argc, char **argv)
{
	char	**args_nbr;
	int	i;
	long	temp_nbr;

	i = 0;
	if (argc == 2)
		args_nbr = ft_split(argv[1], ' ');
	else
		args_nbr = argv + 1;
	while (args_nbr[i])
	{
		temp_nbr = ft_atoi(args_nbr[i]);
		if (!is_integer(args_nbr[i]))
			error_return(IS_INT_E);
		if (temp_nbr < -2147483648 || temp_nbr > 2147483647) // what if nbr > long ??
			error_return(BIG_INT_E);
		i++;
	}
	if (check_duplicate(args_nbr))
		error_return(DUP_E);
	return (args_nbr);
}

t_node	**fill_stack_a(int argc, char **argv)
{
	char	**numbers;
	t_node	**top;
	t_node	*new_node;
	int		i;

	numbers = parse_numbers(argc, argv);
	if (!numbers)
		return (NULL);
	i = 0;
	while (numbers[i])
		i++;
	top = (t_node **)malloc(sizeof(t_node));
	if (!top)
		return (NULL);
	while (i > 0)
	{
		new_node = add_new_node(ft_atoi(numbers[i -1]));
		if (!new_node)
			return (NULL);
		add_node_front(top, new_node);
		i--;
		// new_node = (t_node *)malloc(sizeof(t_node));
		// if (!new_node)
		// 	return (NULL);
		// new_node->next = top;
		// new_node->nbr = ft_atoi(numbers[i - 1]); // use get_number
		// top = new_node;
		// i--;
	}
	if (argc == 2)
		free_grid((void *)numbers);
	return (top);
}
