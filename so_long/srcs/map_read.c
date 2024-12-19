/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:32:33 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/19 22:28:20 by shachowd         ###   ########.fr       */
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

static void	map_validatation(t_map *map, int row, int col)
{
	// if (map->col_c == map->row_c)
	// 	map_error(map, "Map is not rectangular\n");
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
	printf("row [%d]\n", map->row_c);
	map->map = (char **)malloc(sizeof(char *) * (map->row_c + 1));
	if (!map->map)
		map_error(NULL, "Map memory allocation failed\n");
	read_line = ft_line_reader(fd, read_line, BUFFER_SIZE, 0);
	while (read_line) //i < map->row_c
	{
		if (read_line[0] == '\0')
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
		map_error(NULL, "Map is empty\n");
	get_map(map, fd, read_line, &empty_line);
	close(fd);
	if (!map->map)
		map_error(map, "Map copying failed\n");
	if (empty_line > 0)
		map_error(map, "Map has empty line(s)\n");
	printf("empty [%d]\n", empty_line);
	map->col_c = ft_strlen(map->map[0]);
	map_validatation(map, -1, -1);
}

//printf("row count [%d]\n", rows);




// void	map_read(t_map *map, int fd)
// {
// 	int		read_byte;
// 	char	read_line[BUFFER_SIZE];

// 	ft_bzero(read_line, BUFFER_SIZE);
// 	read_byte = read(fd, read_line, BUFFER_SIZE);
// 	close (fd);
// 	if (read_byte == -1)
// 		map_error(NULL, "Map reading error\n");
// 	else if (read_byte == 0)
// 		map_error(NULL, "Map is empty\n");
// 	map->map = ft_split(read_line, '\n');
// 	if (!map->map)
// 		map_error(NULL, "Map splitting error\n");
// 	print_grid(map);
// 	map->col_c = ft_strlen(map->map[0]);
// 	map->row_c = ft_grid_rows(map->map);
// 	map_validatation(map, read_line, -1, -1);
// }
