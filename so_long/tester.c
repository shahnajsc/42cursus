/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:19:42 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/03 11:25:11 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include <stdio.h>

void print_grid(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		printf("Line[%d] %s \n", i, map->map[i]);
		i++;
	}
	printf("\n");
}
