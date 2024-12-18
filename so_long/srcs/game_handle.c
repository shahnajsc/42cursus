/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:42 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/18 10:19:02 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_close(t_slong *slong, int exit_code)
{
	if (!slong)
		return ;
	if (slong->map && slong->map->map)
		free_grid((void **)slong->map->map);
	if (slong->image)
		free_images(slong);
	if (slong->mlx)
		mlx_terminate(slong->mlx);
	exit (exit_code);
}

void	close_hook_handle(void *param)
{
	game_close((t_slong *)param, EXIT_SUCCESS);
}

void	game_movement(t_slong *sl, int next_r, int next_c)
{
	if (sl->map->map[next_r][next_c] == '1')
		return ;
	if (sl->map->map[next_r][next_c] == 'C')
	{
		sl->collec_picked++;
		sl->map->map[next_r][next_c] = '0';
		if (sl->collec_picked == sl->map->collec_c)
			window_load(sl, sl->image->exit_op,
				sl->map->exit_rw, sl->map->exit_cl);
	}
	if (sl->map->map[next_r][next_c] == 'E' &&
				(sl->collec_picked == sl->map->collec_c))
	{
		ft_printf(1, "\n\n!!! YOU WIN !!!\n\n");
		game_close(sl, EXIT_SUCCESS);
	}
	window_load(sl, sl->image->player, next_r, next_c);
	window_load(sl, sl->image->floor, sl->current_r, sl->current_c);
	if (sl->map->map[sl->current_r][sl->current_c] == 'E')
		window_load(sl, sl->image->exit_cl, sl->current_r, sl->current_c);
	sl->moves++;
	sl->current_r = next_r;
	sl->current_c = next_c;
	ft_printf(1, "Total moves: %d \n", sl->moves);
}

void	key_hook_handle(mlx_key_data_t keyprsd, void *param)
{
	t_slong	*slong;
	int		next_c;
	int		next_r;

	slong = (t_slong *)param;
	next_r = slong->current_r;
	next_c = slong->current_c;
	if (slong->map->map[slong->current_r][slong->current_c] != '1')
	{
		if (keyprsd.key == MLX_KEY_ESCAPE && keyprsd.action == MLX_PRESS)
			game_close(slong, EXIT_SUCCESS);
		else if (keyprsd.key == MLX_KEY_UP && keyprsd.action == MLX_PRESS)
			next_r = slong->current_r - 1;
		else if (keyprsd.key == MLX_KEY_DOWN && keyprsd.action == MLX_PRESS)
			next_r = slong->current_r + 1;
		else if (keyprsd.key == MLX_KEY_LEFT && keyprsd.action == MLX_PRESS)
			next_c = slong->current_c - 1;
		else if (keyprsd.key == MLX_KEY_RIGHT && keyprsd.action == MLX_PRESS)
			next_c = slong->current_c + 1;
		else
			return ;
		game_movement(slong, next_r, next_c);
	}
}
