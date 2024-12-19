/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:16:44 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/19 22:28:37 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h> // remove

# define PX 90
# define BUFFER_SIZE 2014

// Image PATH
# define PLAYER_I "./assets/img/player_left.png"
# define WALL_I "./assets/img/wall.png"
# define EXIT_CL_I "./assets/img/exit_close.png"
# define EXIT_OP_I "./assets/img/exit_open.png"
# define COLLECTIBLE_I "./assets/img/collectible.png"
# define FLOOR_I "./assets/img/floor.png"

// structs

typedef struct s_map
{
	char	**map;
	int		row_c;
	int		col_c;
	int		player_c;
	int		collec_c;
	int		exit_c;
	int		path_e;
	int		path_c;
	int		start_rw;
	int		start_cl;
	int		exit_rw;
	int		exit_cl;
}	t_map;

typedef struct s_image
{
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_cl;
	mlx_image_t	*exit_op;
}	t_image;

typedef struct s_slong
{
	t_map	*map;
	mlx_t	*mlx;
	t_image	*image;
	int		current_r;
	int		current_c;
	int		collec_picked;
	int		moves;
}	t_slong;

// Map validation
void	map_read(t_map *map, int fd, char *file_path);

// game
void	game_start(t_slong *slong);
void	game_map_load(t_slong *slong);
void	window_load(t_slong *slong, mlx_image_t *img, int row, int col);
void	key_hook_handle(mlx_key_data_t keypressed, void *param);
void	close_hook_handle(void *param);

// Error Handle
void	file_error(int fd, char *path, char *err_msg);
void	map_error(t_map *map, char *err_msg);
void	free_images(t_slong *slong);
void	game_close(t_slong *slong, int exit_code);
void	game_error(t_slong *slong, char *err_msg, int exit_code);

//utils
void	object_count(t_map *map, int row);
int		map_row_count(char *file_path, char *read_line);

//tester
void 	print_grid(t_map *map);

#endif
