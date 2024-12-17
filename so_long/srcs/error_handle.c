/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:01 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/17 17:05:12 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	file_error(int fd, char *file_name, char *err_msg)
{
	if (fd > 2)
		close (fd);
	ft_printf(2, "Error\n%s %s \n", file_name, err_msg);
	exit (1); // 1 ?!!!
}

void	map_error(t_map *map, char *err_msg)
{
	if (map && map->map)
		free_grid((void **)map->map);
	ft_printf(2, "Error\n%s \n", err_msg);
	exit (1);
}

void	game_error(t_slong *slong, char *err_msg, int exit_code)
{
	ft_printf(2, "Error\n%s \n", err_msg);
	game_close(slong, exit_code);
}

void	free_images(t_slong *slong)
{
	if (slong->image->player)
		mlx_delete_image(slong->mlx, slong->image->player);
	if (slong->image->wall)
		mlx_delete_image(slong->mlx, slong->image->wall);
	if (slong->image->floor)
		mlx_delete_image(slong->mlx, slong->image->floor);
	if (slong->image->collectible)
		mlx_delete_image(slong->mlx, slong->image->collectible);
	if (slong->image->exit_cl)
		mlx_delete_image(slong->mlx, slong->image->exit_cl);
	if (slong->image->exit_op)
		mlx_delete_image(slong->mlx, slong->image->exit_op);
	free(slong->image);
}
