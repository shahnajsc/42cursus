/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:42:11 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/11 17:43:47 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	is_integer(char *nbr)
{
	long	number;
	int	sign;

	sign = 1;
	number = 0;
	while ((*nbr >= 9 && *nbr <= 13) || (*nbr == 32))
		nbr++;
	if (*nbr == '-')
		sign = -1;
	if (sign == -1 || *nbr == '+')
		nbr++;
	if (*nbr < 48 || *nbr > 57)
		return (0);
	while (*nbr >= 48 && *nbr <= 57)
	{
		number = number * 10 + *nbr - '0';
		if ((number * sign < INT_MIN) || (number * sign > INT_MAX))
			return (0);
		nbr++;
	}
	while ((*nbr >= 9 && *nbr <= 13) || (*nbr == 32))
		nbr++;
	if (*nbr)
		return (0);
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
			if (ft_atoi(args_nbr[i]) == ft_atoi(args_nbr[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	is_nbrs_valid(char **numbers)
{
	int	i;

	i = 0;
	if (!numbers)
		return (0);
	while (numbers[i])
	{
		if (*numbers[i] == '\0' || check_white_spaces(numbers[i]))
			return (0);
		if (!is_integer(numbers[i]))
			return (0);
		i++;
	}
	if (check_duplicate(numbers))
		return (0);
	return (1);
}


char	**parse_numbers(int argc, char **argv)
{
	char	**args_nbr;

	if (argc == 2)
		args_nbr = ft_split(argv[0], ' ');
	else
		args_nbr = argv;
	if (!(is_nbrs_valid(args_nbr)))
		error_arguments(args_nbr, argc);
	return (args_nbr);
}

t_node	**fill_stack_a(int argc, char **argv, t_node **stack_a)
{
	char	**numbers;
	t_node	*new_node;
	int		i;

	numbers = parse_numbers(argc, argv);
	if (!numbers)
		return (NULL);
	i = 0;
	while (numbers[i])
		i++;
	while (i > 0)
	{
		new_node = create_new_node(ft_atoi(numbers[i - 1]));
		add_node_top(stack_a, new_node);
		i--;
	}
	if (argc == 2)
		free_grid((void *)numbers);
	return (stack_a);
}

t_node	**fill_stack_b(int argc, char **argv, t_node **stack_a)
{
	char	**numbers;
	t_node	*new_node;
	int		i;

	numbers = parse_numbers(argc, argv);
	if (!numbers)
		return (NULL);
	i = 0;
	while (numbers[i])
		i++;
	while (i > 0)
	{
		new_node = create_new_node(ft_atoi(numbers[i - 1]));
		add_node_bottom(stack_a, new_node);
		i--;
	}
	if (argc == 2)
		free_grid((void *)numbers);
	return (stack_a);
}

// static int	is_int(char *s)
// {
// 	long	number;
// 	int		sign;

// 	number = 0;
// 	sign = 1;
// 	while (is_white_space(*s))
// 		s++;
// 	if (*s == '+' || *s == '-')
// 		if (*s++ == '-')
// 			sign = -1;
// 	if (*s < '0' || *s > '9')
// 		return (0);
// 	while (*s >= '0' && *s <= '9')
// 	{
// 		number = number * 10 + *s++ - '0';
// 		if ((number * sign < MIN_INT) || (number * sign > MAX_INT))
// 			return (0);
// 	}
// 	while (is_white_space(*s))
// 		s++;
// 	if (*s)
// 		return (0);
// 	return (1);
// }

// static int	is_invalid(char **array)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (array[++i])
// 	{
// 		if (*array[i] == '\0' || is_all_white_space(array[i]))
// 			return (1);
// 		if (!is_int(array[i]))
// 			return (1);
// 		j = -1;
// 		while (++j < i)
// 			if (ft_atoi(array[j]) == ft_atoi(array[i]))
// 				return (1);
// 	}
// 	return (0);
// }
