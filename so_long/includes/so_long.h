/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:16:44 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/03 16:10:49 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries
# include "../libft/includes/libft.h"
# include <stdio.h> // remove it

# define PX 64
// MAX_COL = 3840 / PX
# define MAX_COL 60
// MAX_ROW = 2160 / PX
# define MAX_ROW 33
// BUFFER_SIZE  > MAX_COL * MAX_ROW
# define BUFFER_SIZE 2014

// structs

typedef struct s_map
{
	char	**map;
	int		row_c;
	int		col_c;
	int		player_c;
	int		collec_c;
	int		exit_c;
} t_map;

// Utils
int	ft_grid_len(char **grid);

// Map validation
void	map_read(t_map *map, int fd);

// Error Handle
void	path_error(int fd, char *path, char *err_msg);
void	map_error(t_map *map, char *read_line, char *err_msg);

// tester
void print_grid(t_map *map);
#endif