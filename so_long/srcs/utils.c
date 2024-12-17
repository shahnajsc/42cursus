/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:59:41 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/17 12:51:59 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	object_count(t_map *map, int row)
{
	int	i;

	i = 0;
	while (map->map[row][i])
	{
		if (map->map[row][i] == 'P')
		{
			map->player_c++;
			map->start_rw = row;
			map->start_cl = i;
		}
		else if (map->map[row][i] == 'C')
			map->collec_c++;
		else if (map->map[row][i] == 'E')
		{
			map->exit_c++;
			map->exit_rw = row;
			map->exit_cl = i;
		}
		i++;
	}
}

void	check_empty_line(t_map *map, char *read_line)
{
	int	line_c;
	int	i;

	line_c = 0;
	i = 0;
	while (read_line[i])
	{
		if (read_line[i] == '\n')
			line_c++;
		i++;
	}
	if (line_c > (map->row_c - 1))
		map_error(map, "Map has empty line\n");
}
