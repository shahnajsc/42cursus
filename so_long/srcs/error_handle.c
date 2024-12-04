/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:01 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/04 14:16:57 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	free_grid(void **ptr)
// {
// 	int	i;

// 	if (!ptr)
// 		return ;
// 	i = 0;
// 	while (ptr[i] != NULL)
// 	{
// 		free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	ptr = NULL;
// }

void	file_error(int fd, char *file_name, char *err_msg)
{
	if (fd > 2)
		close (fd);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(err_msg, 2);
	exit (1); // 1 ?!!!
}

void	map_error(t_map *map, char *read_line, char *err_msg)
{
	if (map && map->map)
		free_grid((void **)map->map);
	if (read_line)
		free(read_line);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit (1);
}
