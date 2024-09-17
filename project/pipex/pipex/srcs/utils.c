/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:50:05 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/17 15:48:03 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>


int	main(int argc, char **argv)
{
	int i;
	
	i = 0;
	while (argc > 0)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	return (0);
}