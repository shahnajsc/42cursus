/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:07 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/20 11:08:41 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_map(t_map *map)
{
	map->map = NULL;
	map->row_c = 0;
	map->col_c = 0;
	map->player_c = 0;
	map->exit_c = 0;
	map->collec_c = 0;
	map->path_e = 0;
	map->path_c = 0;
	map->start_rw = 0;
	map->start_cl = 0;
	map->exit_rw = 0;
	map->exit_cl = 0;
}

static void	init_slong(t_slong *slong, t_map *map)
{
	slong->map = map;
	slong->mlx = NULL;
	slong->image = NULL;
	slong->current_r = map->start_rw;
	slong->current_c = map->start_cl;
	slong->collec_picked = 0;
	slong->moves = 0;
}

static int	map_file_validation(char *file)
{
	int	len;
	int	fd;

	if (file[0] == '\0' || check_white_spaces(file))
		file_error(0, file, " map file not found\n");
	len = ft_strlen(file);
	if (len <= 4 || (len > 4 && file[len - 5] == '/'))
		file_error(0, file, " is an invalid file type\n");
	if (file[len - 4] != '.' || file[len - 3] != 'b'
		|| file[len - 2] != 'e' || file[len - 1] != 'r')
		file_error(0, file, " is an invalid file type\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		file_error(fd, file, " file error\n");
	return (fd);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_slong	slong;
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n Wrong number of arguments\n", 2);
		return (1);
	}
	fd = map_file_validation(argv[1]);
	init_map(&map);
	map_read(&map, fd, argv[1]);
	ft_bzero(&slong, sizeof(slong));
	init_slong(&slong, &map);
	game_start(&slong);
	game_close(&slong, EXIT_SUCCESS);
}
