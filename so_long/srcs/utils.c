/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:59:41 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/03 10:50:20 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_grid_len(char **grid)
{
	int	len;

	len = 0;
	if (!grid)
		return (0);
	while (grid[len])
		len++;
	return (len);
}
