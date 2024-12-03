/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:32:33 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/03 16:50:53 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void object_count(t_map *map, int row)
{
	int	i;

	i = 0;
	while (map->map[row][i])
	{
		if (map->map[row][i] == 'P')
			map->player_c++;
		else if (map->map[row][i] == 'C')
			map->collec_c++;
		else if (map->map[row][i] == 'E')
			map->exit_c++;
		i++;
	}
}

static void	check_empty_line(t_map *map, char *read_line)
{
	int	line_c;
	int	i;

	line_c = 0;
	i = 0;
	//print_grid(map);
	while (read_line[i])
	{
		if (read_line[i] == '\n')
			line_c++;
		i++;
	}
	if (line_c > (map->row_c))
		map_error(map, read_line, "Map has empty line");
}

static void object_validation(t_map *map, char *read_line)
{
	if (map->player_c < 1)
		map_error(map, read_line, "No player exists");
	if (map->player_c > 1)
		map_error(map, read_line, "More then one player");
	if (map->exit_c < 1)
		map_error(map, read_line, "No exit available");
	if (map->exit_c > 1)
		map_error(map, read_line, "More then one exit");
	if (map->collec_c < 1)
		map_error(map, read_line, "No collectibles found");
}

static void	map_validatation(t_map *map, char *read_line)
{
	int	row;
	int	col;

	row = 0;
	check_empty_line(map, read_line);
	if (map->col_c <= map->row_c)
		map_error(map, read_line, "Map is not rectangle");
	if (map->row_c > MAX_ROW || map->col_c > MAX_COL)
		map_error(map, read_line, "Map is larger then expected");
	while (row < map->row_c)
	{
		if ((int)ft_strlen(map->map[row]) != map->col_c)
			map_error(map, read_line, "Map is not rectangular");
		object_count(map, row);
		col = -1;
		while (++col < map->col_c)
		{
			ft_putchar_fd(map->map[row][col], 1);
			if (!ft_strchr("01PCE\n", map->map[row][col]))
				map_error(map, read_line, "Invalid character found");
			if ((row == 0 || row == map->row_c - 1 || col == 0 ||
					col == map->col_c - 1) && map->map[row][col] != '1')
				map_error(map, read_line, "Map is not srounded by walls");
		}
		ft_putchar_fd('\n', 1);
		row++;
	}
	object_validation(map, read_line);
}

void	map_read(t_map *map, int fd)
{
	int		read_byte;
	char	*read_line;

	read_line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!read_line)
		map_error(NULL, NULL, "Map memory allocation failed");
	read_byte = read(fd, read_line, BUFFER_SIZE);
	close (fd);
	if (read_byte == -1)
		map_error(NULL, read_line, "Map reading error");
	else if (read_byte == 0)
		map_error(NULL, read_line, "Map is empty");
	else if (read_byte > (MAX_ROW * (MAX_COL + 1)))
		map_error(NULL, read_line, "Map is largeer then expected");
	map->map = ft_split(read_line, '\n');
	if (!map->map)
		map_error(NULL, read_line, "Map splitting error");
	map->col_c = ft_strlen(map->map[0]);
	map->row_c = ft_grid_len(map->map);
	map_validatation(map, read_line);
	free(read_line);
}