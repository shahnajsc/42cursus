/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:42:11 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/03 22:47:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	is_int(int *nbr)
{
	int i;

	i = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);

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
			if (args_nbr[i] == args_nbr[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


char	**parse_numbers(char **argv, int argc)
{
	char	**args_nbr;
	int	i;
	int	temp_nbr;

	if (argc == 2)
	{
		i = 0;
		args_nbr = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		args_nbr = argv;
	}
	while (args_nbr[i])
	{
		temp_nbr = ft_atoi(args_nbr[i]);
		if (temp_nbr < -2147483648 || temp_nbr > 2147483647)
			error_return(BIG_INT_E);
		if (!is_int(temp_nbr))
			error_return(IS_INT_E);
	}
	if (check_duplicate(args_nbr))
		error_return(DUP_E);
	return (args_nbr);
}

t_node	*fill_stack_a(int argc, char **argv)
{
	char	**numbers;
	t_node	*top;
	t_node	*new_node;
	int		i;

	 // error_handle
	i = argc - 1;
	numbers = parse_numbers(argc, argv);
	top = 0;
	while (i > 0)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->next = top;
		new_node->nbr = ft_atoi(numbers[i - 1]); // use get_number
		top = new_node;
		i--;
	}
	return (top);
}
