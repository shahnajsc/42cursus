/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:07 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/11 12:47:22 by shachowd         ###   ########.fr       */
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
	map->path_e = 0;
	map->path_c = 0;
	map->start_r = 0;
	map->start_c = 0;
}

static void	init_slong(t_slong *slong, t_map *map)
{
	slong->map = map;
	slong->mlx = NULL;
}

static int	map_file_validation(char *file)
{
	int	len;
	int	fd;

	if (file[0] == '\0' || check_white_spaces(file))
		file_error(0, file, "Map file not found");
	len = ft_strlen(file);
	if (file[len - 4] != '.' || file[len - 3] != 'b'
		|| file[len - 2] != 'e' || file[len - 1] != 'r')
		file_error(0, file, " is an invalid file type");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		file_error(fd, file, " file error"); // use srt erro
	return (fd);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_slong slong;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Errortttt\n", 2);
		return (1);
	}
	fd = map_file_validation(argv[1]);
	//ft_putnbr_fd(fd, 2);
	init_map(&map);
	// //ft_putnbr_fd(fd, 1);
	map_read(&map, fd);
	//ft_bzero(&slong, sizeof(slong));
	init_slong(&slong, &map);
	game_start(&slong);
	// map_error(&map, "Valid map");
	map_error(&map, "Exiting game");
}
