/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:50:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/04 14:16:25 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_grid_dup(char **grid)
{
	int		rows;
	int		count;
	char	**dup_grid;

	count = 0;
	rows = ft_grid_rows(grid);
	dup_grid = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!dup_grid)
		return (NULL);
	while (count < rows)
	{
		dup_grid[count] = ft_strdup(grid[count]);
		if (!dup_grid[count])
		{
			free_grid((void **)grid);
			return (NULL);
		}
		count++;
	}
	return (dup_grid);
}
