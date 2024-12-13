/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:58:49 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/10 19:59:24 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static mlx_image_t	*texture_process(t_slong *slong, char *img_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(img_path);
	if (!texture)
	{
		printf("texture erro\n");
		game_error(slong, "texture fail", EXIT_FAILURE); // change msg
	}
	image = mlx_texture_to_image(slong->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		printf("image erro\n");
		game_error(slong, "image fail", EXIT_FAILURE); // change msg
	}
	return(image);
}

static void	image_process(t_slong *slong)
{
	slong->image = ft_calloc(1, sizeof(t_image));
	if (!slong->image)
		game_error(slong, "image calloc failed", EXIT_FAILURE); // change msg
	slong->image->player = texture_process(slong, PLAYER_I);
	slong->image->wall = texture_process(slong, WALL_I);
	slong->image->floor = texture_process(slong, FLOOR_I);
	slong->image->collectible = texture_process(slong, COLLECTIBLE_I);
	slong->image->exit_cl = texture_process(slong, EXIT_CL_I);
	slong->image->exit_op = texture_process(slong, EXIT_OP_I);

}

void	window_img_load(t_slong *slong, mlx_image_t *img, int row, int col)
{
	int win_image;

	win_image = mlx_image_to_window(slong->mlx, img, col * PX, row * PX);
	if (win_image < 0)
		game_error(slong, "win_img error", EXIT_FAILURE);
}

void	game_map_load(t_slong *slong)
{
	int	row;
	int	col;

	image_process(slong);
	row = -1;
	while (++row < slong->map->row_c)
	{
		col = -1;
		while (++col < slong->map->col_c)
		{
			window_img_load(slong, slong->image->floor, row, col);
			if (slong->map->map[row][col] == '1')
				window_img_load(slong, slong->image->wall, row, col);
			else if (slong->map->map[row][col] == 'C')
				window_img_load(slong, slong->image->collectible, row, col);
			else if (slong->map->map[row][col] == 'E')
			{
				window_img_load(slong, slong->image->exit_op, row, col);
				window_img_load(slong, slong->image->exit_cl, row, col);
			}
			else if (slong->map->map[row][col] == 'P')
				window_img_load(slong, slong->image->player, row, col);
		}
	}
}
