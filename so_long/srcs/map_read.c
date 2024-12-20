/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:32:33 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/20 16:22:57 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

static void	map_validatation(t_map *map, int empty_line, int row, int col)
{
	if (map->row_c < 3 || map->col_c < 3)
		map_error(map, "Map is incomplete\n");
	if (empty_line > 0)
		map_error(map, "Map has empty line(s)\n");
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
			if (!ft_strchr("01PCE", map->map[row][col]))
				map_error(map, "Invalid character found\n");
			if ((row == 0 || row == map->row_c - 1 || col == 0
					|| col == map->col_c - 1) && map->map[row][col] != '1')
				map_error(map, "Map is not srounded by walls\n");
		}
	}
	object_validation(map);
	object_path_validation(map);
}

void	get_map(t_map *map, int fd, char *read_line, int *empty_line)
{
	int		i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->row_c + 1));
	if (!map->map)
		map_error(NULL, "Map memory allocation failed\n");
	read_line = ft_line_reader(fd, read_line, BUFFER_SIZE, 0);
	while (read_line)
	{
		if (read_line[0] == '\n')
			(*empty_line)++;
		map->map[i] = ft_strtrim(read_line, "\n");
		if (!map->map[i])
		{
			free(read_line);
			map_error(map, "Map reading failed\n");
		}
		free(read_line);
		read_line = ft_line_reader(fd, read_line, BUFFER_SIZE, 0);
		i++;
	}
	free(read_line);
	map->map[i] = NULL;
}

void	map_read(t_map *map, int fd, char *file_path)
{
	char	*read_line;
	int		empty_line;

	read_line = NULL;
	empty_line = 0;
	map->row_c = map_row_count(file_path, read_line);
	if (map->row_c == 0)
	{
		close(fd);
		map_error(NULL, "Map is empty\n");
	}
	get_map(map, fd, read_line, &empty_line);
	close(fd);
	if (!map->map)
		map_error(map, "Map copying failed\n");
	map->col_c = ft_strlen(map->map[0]);
	map_validatation(map, empty_line, -1, -1);
}
