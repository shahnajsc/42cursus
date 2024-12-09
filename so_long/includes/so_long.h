/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:16:44 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/09 16:57:52 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h> // remove it

# define PX 70
// MAX_COL = 3840 / PX
# define MAX_COL 60
// MAX_ROW = 2160 / PX
# define MAX_ROW 33
// BUFFER_SIZE  > MAX_COL * MAX_ROW
# define BUFFER_SIZE 2014

// enum
typedef enum e_object
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
