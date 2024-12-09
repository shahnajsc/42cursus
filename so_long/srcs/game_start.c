/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/09 16:52:01 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_start(t_slong *slong)
{
	slong->mlx = mlx_init(slong->map->col_c * PX, slong->map->row_c * PX, "so_long", 1);
	mlx_loop(slong->mlx);
}
