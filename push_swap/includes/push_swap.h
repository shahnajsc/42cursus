/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:36:00 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/04 17:01:43 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// library
# include "../libft/includes/libft.h"
// libft lib # include <stdlib.h> # include <unistd.h> # include <stdarg.h> # include <fcntl.h>

// variable

typedef struct  s_node
{
	int			nbr;
	struct s_node	*next;
	//struct node	*prev;
}	t_node;

typedef enum s_error
{
	DUP_E,
	IS_INT_E,
	BIG_INT_E,
}	t_error;

// arguments handle
t_node		**fill_stack_a(int argc, char **argv);

// t_node operation functions
t_node	*add_new_node(int number);
void	add_node_front(t_node **top, t_node *new_node);


// test functions **** remove in final version
void	display_stack(t_node *stack_a);

// error handle
void	free_grid(void **ptr);
void	free_stack(t_node *stack);
void	error_return(t_error err_type);

#endif
