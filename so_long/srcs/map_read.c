/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:32:33 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/17 12:53:39 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	object_validation(t_map *map)
{
	if (map->player_c < 1)
		map_error(map, "No player exists\n");
	if (map->player_c > 1)
		map_error(map, "More then one player\n");
	if (map->exit_c < 1)
		map_error(map, "No exit available\n");
	if (map->exit_c > 1)
		map_error(map, "More then one exit\n");
	if (map->collec_c < 1)
		map_error(map, "No collectibles found\n");
}

static void	map_visited_fill(t_map *map, char **temp_map, int row, int col)
{
	if (temp_map[row][col] == '1')
		return ;
	if (temp_map[row][col] == 'C')
		map->path_c++;
	else if (temp_map[row][col] == 'E')
		map->path_e = 1;
	temp_map[row][col] = '1';
	map_visited_fill(map, temp_map, row + 1, col);
	map_visited_fill(map, temp_map, row - 1, col);
	map_visited_fill(map, temp_map, row, col + 1);
	map_visited_fill(map, temp_map, row, col - 1);
}

static void	object_path_validation(t_map *map)
{
	char	**temp_map;

	temp_map = ft_grid_dup(map->map);
	if (!temp_map)
		map_error(map, "Duplicating map is failed\n");
	map_visited_fill(map, temp_map, map->start_rw, map->start_cl);
	free_grid((void **)temp_map);
	if (!map->path_e)
		map_error(map, "Valid path to exit is unavailable\n");
	if (map->path_c != map->collec_c)
		map_error(map, "Valid path to collectibles is unavailable\n");
}

static void	map_validatation(t_map *map, char *read_line, int row, int col)
{
	check_empty_line(map, read_line);
	if (map->col_c == map->row_c)
		map_error(map, "Map is not rectangular\n");
	while (++row < map->row_c)
	{
		if ((int)ft_strlen(map->map[row]) != map->col_c)
			map_error(map, "Map is not rectangular\n");
		object_count(map, row);
		col = -1;
		while (++col < map->col_c)
		{
			if (!ft_strchr("01PCE\n", map->map[row][col]))
				map_error(map, "Invalid character found\n");
			if ((row == 0 || row == map->row_c - 1 || col == 0
					|| col == map->col_c - 1) && map->map[row][col] != '1')
				map_error(map, "Map is not srounded by walls\n");
		}
	}
	object_validation(map);
	object_path_validation(map);
}

void	map_read(t_map *map, int fd)
{
	int		read_byte;
	char	read_line[BUFFER_SIZE];

	ft_bzero(read_line, BUFFER_SIZE);
	read_byte = read(fd, read_line, BUFFER_SIZE);
	close (fd);
	if (read_byte == -1)
		map_error(NULL, "Map reading error\n");
	else if (read_byte == 0)
		map_error(NULL, "Map is empty\n");
	map->map = ft_split(read_line, '\n');
	if (!map->map)
		map_error(NULL, "Map splitting error\n");
	map->col_c = ft_strlen(map->map[0]);
	map->row_c = ft_grid_rows(map->map);
	map_validatation(map, read_line, -1, -1);
}
