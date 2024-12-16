/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:42 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/16 17:47:20 by shachowd         ###   ########.fr       */
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
	if(slong->mlx)
		mlx_terminate(slong->mlx);
	exit (exit_code);
}
void	close_hook_handle(void *param)
{
	game_close((t_slong *)param, EXIT_SUCCESS);
}

void	game_movement(t_slong *slong, int next_r, int next_c)
{
	if (slong->map->map[next_r][next_c] == '1')
		return ;
	if (slong->map->map[next_r][next_c] == 'C')
	{
		slong->collec_picked++;
		slong->map->map[next_r][next_c] = '0';
			//if (slong->collec_picked == slong->map->collec_c)
			 // change exit img
	}
	if (slong->map->map[next_r][next_c] == 'E' &&
				(slong->collec_picked == slong->map->collec_c))
	{
			ft_putstr_fd("you won the game", 1);
			game_close(slong, EXIT_SUCCESS);
	}
	window_img_load(slong, slong->image->player, next_r, next_c);
	window_img_load(slong, slong->image->floor, slong->current_r, slong->current_c);
	if (slong->map->map[slong->current_r][slong->current_c] == 'E')
		window_img_load(slong, slong->image->exit_cl, slong->current_r, slong->current_c);
	slong->moves++;
	slong->current_r = next_r;
	slong->current_c = next_c;
	ft_putstr_fd("Total moves: ", 1);
	ft_putnbr_fd(slong->moves, 1);
	ft_putstr_fd("\n", 1);
}

void	key_hook_handle(mlx_key_data_t keypressed, void *param)
{
	t_slong *slong;
	int	next_c;
	int	next_r;

	slong = (t_slong *)param;
	next_r = slong->current_r;
	next_c = slong->current_c;
	if (slong->map->map[slong->current_r][slong->current_c] != '1')
	{
		if (keypressed.key == MLX_KEY_ESCAPE && keypressed.action == MLX_PRESS)
			game_close(slong, EXIT_SUCCESS);
		else if (keypressed.key == MLX_KEY_UP && keypressed.action == MLX_PRESS)
			next_r = slong->current_r - 1;
		else if (keypressed.key == MLX_KEY_DOWN && keypressed.action == MLX_PRESS)
			next_r = slong->current_r + 1;
		else if (keypressed.key == MLX_KEY_LEFT && keypressed.action == MLX_PRESS)
			next_c = slong->current_c - 1;
		else if (keypressed.key == MLX_KEY_RIGHT && keypressed.action == MLX_PRESS)
			next_c = slong->current_c + 1;
		else
			return ;
		game_movement(slong, next_r, next_c);
	}
}
//still reachable: 318,003 bytes in 3,107 blocks
