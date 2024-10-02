/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:07:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/10/02 16:23:27 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc != 2) // one av input or multi input???
		exit(1); // code 1 or 0?
	else
		ft_putstr_fd(argv[1], 1);
}
