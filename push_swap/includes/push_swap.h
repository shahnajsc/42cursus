/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:36:00 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/14 17:51:09 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// library
# include "../libft/includes/libft.h"
// libft lib # include <stdlib.h> # include <unistd.h> # include <stdarg.h> # include <fcntl.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// struct

typedef struct	s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_pswap
{
	t_node	**a;
	t_node	**b;
	int		length;
}	t_pswap;


typedef enum s_error
{
	DUP_E,
	IS_INT_E,
	BIG_INT_E,
}	t_error;

// arguments handle
t_node		**fill_stack_a(int argc, char **argv, t_node **stack_a);
t_node		**fill_stack_b(int argc, char **argv, t_node **stack_a);

// t_node operation functions
t_node	*create_new_node(int number);
void	add_node_top(t_node **top, t_node *new_node);
void	add_node_bottom(t_node **top, t_node *new_node);
void	delete_node_top(t_node **top);
void	swap_top(t_node **stack);
void	push_top(t_node **stack_to, t_node **stack_from);
void	rotate_up(t_node **stack);
void	reverse_rotate(t_node **stack);

// sorting functions
int	stack_length(t_node **stack);
int	is_sorted(t_node **stack_a);
void	sort_stack(t_pswap *p_swap);

// operation functions
void	sa(t_pswap *stacks);
void	pa(t_pswap *stacks);
void	ra(t_pswap *stacks);
void	rra(t_pswap *stacks);
void	sb(t_pswap *stacks);
void	pb(t_pswap *stacks);
void	rb(t_pswap *stacks);
void	rrb(t_pswap *stacks);

// test functions **** remove in final version
void	display_stack(t_node **stack_a);

// error handle
void	free_grid(void **ptr);
void	free_stack(t_node **stack);
void	error_arguments(char **args_nbr, int argc);

#endif
