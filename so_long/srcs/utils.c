/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:59:41 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/19 22:24:24 by shachowd         ###   ########.fr       */
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

int	map_row_count(char *file_path, char *read_line)
{
	int	rows;
	int	fd;

	rows = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		file_error(fd, file_path, " file error while counting map rows\n");
	read_line = ft_line_reader(fd, read_line, BUFFER_SIZE, 0);
	while (read_line)
	{
		rows++;
		free(read_line);
		read_line = ft_line_reader(fd, read_line, BUFFER_SIZE, 0);
	}
	close(fd);
	if (read_line)
		free(read_line);
	return (rows);
}
