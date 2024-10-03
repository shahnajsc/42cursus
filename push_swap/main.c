/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:07:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/03 16:02:41 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_node *a;

	if (argc == 1) // one av input or multi input???
	{
		printf("%s\n", argv[1]);
		exit(1); // code 1 or 0?
	}
	a =  fill_stack_a(argc, argv);
	display_stack(a);
	free_stack(a);
}
