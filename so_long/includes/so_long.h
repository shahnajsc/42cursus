/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:16:44 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/10 19:56:16 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h> // remove it

# define PX 170
# define MAX_COL 60
# define MAX_ROW 33
# define BUFFER_SIZE 2014

// Image PATH
# define PLAYER_I "./assets/img/player.png"
# define WALL_I "./assets/img/wall.png"
# define EXIT_I "./assets/img/exit.png"
# define COLLECTIBLE_I "./assets/img/collectible.png"
# define SPACE_I "./assets/img/space.png"

// enum
typedef enum s_object
{
	P,
	E,
	C
} t_object;

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
	int		start_r;
	int		start_c;
} t_map;

typedef struct s_slong
{
	t_map	*map;
	mlx_t	*mlx;
} t_slong;


// Utils

// Map validation
void	map_read(t_map *map, int fd);

// game
void	game_start(t_slong *slong);

// Error Handle
void	file_error(int fd, char *path, char *err_msg);
void	map_error(t_map *map, char *read_line, char *err_msg);

// tester
void print_grid(t_map *map);
#endif
