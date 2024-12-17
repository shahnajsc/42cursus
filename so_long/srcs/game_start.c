/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/17 12:46:03 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_start(t_slong *slong)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	slong->mlx = mlx_init(slong->map->col_c * PX,
			slong->map->row_c * PX, "so_long", true);
	if (!slong->mlx)
		game_error(slong, "mlx initiation failed", EXIT_FAILURE);
	game_map_load(slong);
	mlx_key_hook(slong->mlx, key_hook_handle, slong);
	mlx_close_hook(slong->mlx, close_hook_handle, slong);
	mlx_loop(slong->mlx);
	mlx_terminate(slong->mlx);
}
