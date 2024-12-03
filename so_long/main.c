/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:07 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/03 16:29:51 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void init_map(t_map *map)
{
	map->map = NULL;
	map->row_c = 0;
	map->col_c = 0;
	map->player_c = 0;
	map->exit_c = 0;
	map->collec_c = 0;
}
static int	map_path_validate(char *path)
{
	int	path_len;
	int	fd;

	if (path[0] == '\0' || check_white_spaces(path))
		path_error(0, path, "Path is empty");
	path_len = ft_strlen(path);
	if (path[path_len - 4] != '.' || path[path_len - 3] != 'b'
		|| path[path_len - 2] != 'e' || path[path_len - 1] != 'r')
		path_error(0, path, " is an invalid file type");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		path_error(fd, path, " file error"); // use srt erro
	return (fd);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	fd = map_path_validate(argv[1]);
	init_map(&map);
	//ft_putnbr_fd(fd, 1);
	map_read(&map, fd);

}
