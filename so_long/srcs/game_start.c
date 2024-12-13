/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/13 13:59:14 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_start(t_slong *slong)
{
	printf(" before game start erro\n");
	slong->mlx = mlx_init(slong->map->col_c * PX, slong->map->row_c * PX, "so_long", true);
	if (!slong->mlx)
	{
		printf("game start erro\n");
		printf("game ptr: %p\n", slong->mlx);
		game_error(slong, "mlx init fail", EXIT_FAILURE); //msg
	}
	printf("game start worked\n");
	game_map_load(slong);
	mlx_key_hook(slong->mlx, key_hook_handle, slong);
	mlx_close_hook(slong->mlx, close_hook_handle, slong);
	mlx_loop(slong->mlx);
	mlx_terminate(slong->mlx);
}

// {
// 	mlx_texture_t *tex_player;
// 	mlx_texture_t *tex_player2;
// 	mlx_image_t *img_player;
// 	mlx_image_t *img_player2;
// 	int row = -1;
// 	int col;

// 	print_grid(slong->map);
// 	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
// 	slong->mlx = mlx_init(slong->map->col_c * PX, slong->map->row_c * PX, "so_long", 1);
// 	tex_player = mlx_load_png(PLAYER_I);
// 	if (!tex_player)
// 		printf("texture erro\n");
// 	else
// 		printf("texture okkk\n");
// 	img_player = mlx_texture_to_image(slong->mlx, tex_player);
// 	if (!img_player)
// 		printf("image erro\n");
// 	else
// 		printf("image okkk\n");
// 	mlx_delete_texture(tex_player);
// 	tex_player2 = mlx_load_png(PLAYER_I);
// 	if (!tex_player2)
// 		printf("texture2 erro\n");
// 	else
// 		printf("texture2 okkk\n");
// 	img_player2 = mlx_texture_to_image(slong->mlx, tex_player2);
// 	if (!img_player2)
// 		printf("image2 erro\n");
// 	else
// 		printf("image2 okkk\n");
// 	mlx_delete_texture(tex_player2);
// 	printf("total row %d\n", slong->map->row_c);
// 	printf("total col %d\n", slong->map->col_c);
// 	while (++row < slong->map->row_c)
// 	{
// 		printf("inside[%d]: ", row);
// 		col = -1;
// 		while (++col < slong->map->col_c)
// 		{
// 			printf("%c", slong->map->map[row][col]);
// 			if (slong->map->map[row][col] == '1')
// 				mlx_image_to_window(slong->mlx, img_player, col * PX, row * PX);
// 			else
// 				mlx_image_to_window(slong->mlx, img_player2, col * PX, row * PX);
// 		}
// 		printf("\n");
// 	}
// }
