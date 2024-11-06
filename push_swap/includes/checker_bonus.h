/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:36:00 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/05 15:45:12 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

// library
# include "../libft/includes/libft.h"
// libft lib # include <stdlib.h> # include <unistd.h>
// # include <stdarg.h> # include <fcntl.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// struct

typedef struct s_node
{
	int				nbr;
	int				index;
	int				position;
	struct s_node	*next;
}	t_node;

typedef struct s_pswap
{
	t_node	**a;
	t_node	**b;
}	t_pswap;

// argument process
t_node	*fill_stack_a(int argc, char **argv, t_node **stack_a);

// operations
void	sa(t_pswap *stacks);
void	pa(t_pswap *stacks);
void	ra(t_pswap *stacks);
void	rra(t_pswap *stacks);
void	sb(t_pswap *stacks);
void	pb(t_pswap *stacks);
void	rb(t_pswap *stacks);
void	rrb(t_pswap *stacks);
void	ss(t_pswap *stacks);
void	rr(t_pswap *stacks);
void	rrr(t_pswap *stacks);

//operation utils
t_node	*create_new_node(int number, int index, int position);
void	add_node_top(t_node **top, t_node *new_node);
void	add_node_bottom(t_node **top, t_node *new_node);
void	delete_node_top(t_node **top);
void	swap_top(t_node **stack);
void	push_top(t_node **stack_to, t_node **stack_from);
void	rotate_up(t_node **stack);
void	reverse_rotate(t_node **stack);

// read functions
char	*reader(char *line, int buffer_size, int index);

//checker function
int		checker(t_pswap *psp);

// common utils
int		get_index(char **numbers, int nbr);
int		is_sorted(t_node **stack_a);
int		stack_length(t_node **stack);

// error handle
int		operation_error(void);
void	error_arguments(char **args_nbr, int argc);
void	free_stack(t_node **stack);
void	free_grid(void **ptr);

#endif
