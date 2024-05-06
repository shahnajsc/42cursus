/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:05:28 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/29 14:16:44 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write(fd, s++, 1);
	}
	write(fd, "\n", 1);
}
/*

#include <fcntl.h>
int main(void)
{
	char *s = "abcDEF";
	int file;

	file = open("putendl_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd(s, file);
	close(file);
    
    s = "12345ERT";
    ft_putendl_fd(s, 1);

    return (0);
}
*/
