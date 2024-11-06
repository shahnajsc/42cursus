/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:36:00 by shachowd          #+#    #+#             */
/*   Updated: 2024/11/06 11:00:57 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int		length_a;
	int		cost_a;
	int		cost_b;
	int		total_cost;
	int		rotate_flag;
}	t_pswap;

// arguments handle
t_node	*fill_stack_a(int argc, char **argv, t_node **stack_a);
int		get_index(char **numbers, int nbr);

// t_node operation functions
t_node	*create_new_node(int number, int pos_val, int position);
void	add_node_top(t_node **top, t_node *new_node);
void	add_node_bottom(t_node **top, t_node *new_node);
void	delete_node_top(t_node **top);
void	swap_top(t_node **stack);
void	push_top(t_node **stack_to, t_node **stack_from);
void	rotate_up(t_node **stack);
void	reverse_rotate(t_node **stack);

// sorting utils
int		stack_length(t_node **stack);
int		is_sorted(t_node **stack_a);
void	set_position(t_node **stack);
t_node	*get_tail_node(t_node **stack);
int		get_position(t_pswap *psp, int nbr);
int		get_position_a(t_node **stack, int nbr);
int		min_value(t_node **stack);
int		max_value(t_node **stack);
int		median(t_node **stack);

// sorting functions
void	sort_stack(t_pswap *p_swap);
void	sort_three(t_pswap *psp);
void	sort_bigger(t_pswap *psp);
void	push_to_b(t_pswap *psp);
void	push_back_to_a(t_pswap *psp);

// operation functions
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

//push and cost calculation function
void	op_rarb(t_pswap *psp);
void	op_rrarrb(t_pswap *psp);
void	op_rarrb(t_pswap *psp);
void	op_rrarb(t_pswap *psp);
int		cost_rarb(t_pswap *psp, int rotate_a, int rotate_b);
int		cost_rrarrb(t_pswap *psp, int rotate_a, int rotate_b);
int		cost_rarrb(t_pswap *psp, int rotate_a, int rotate_b);
int		cost_rrarb(t_pswap *psp, int rotate_a, int rotate_b);

// error handle
void	free_grid(void **ptr);
void	free_stack(t_node **stack);
void	error_arguments(char **args_nbr, int argc);

#endif
