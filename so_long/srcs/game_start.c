/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/10 21:01:23 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_start(t_slong *slong)
{
	mlx_texture_t *tex_player;
	mlx_image_t *img_player;
	int row = -1;
	int col;

	slong->mlx = mlx_init(slong->map->col_c * PX, slong->map->row_c * PX, "so_long", 1);
	tex_player = mlx_load_png("./assets/img/player.png");
	if (!tex_player)
		printf("texture erro\nr");
	img_player = mlx_texture_to_image(slong->mlx, tex_player);
	if (!img_player)
		printf("image erro\nr");
	mlx_delete_texture(tex_player);
	while (++row < slong->map->row_c)
	{
		col = -1;
		while (++col < slong->map->col_c)
		{
			if (slong->map->map[row][col] == 'P')
				mlx_image_to_window(slong->mlx, img_player, slong->map->col_c * PX, slong->map->row_c * PX);
			else
				mlx_image_to_window(slong->mlx, img_player, slong->map->col_c * PX, slong->map->row_c * PX);
		}
	}
	mlx_loop(slong->mlx);
}
