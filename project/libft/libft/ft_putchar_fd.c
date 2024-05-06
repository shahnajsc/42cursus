/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:30:05 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/29 13:43:49 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
int main(void)
{
	char c;
	int file;

	c = 'R';
	file = open("putchar_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd(c, file);
	close(file);
    
    c = 'D';
    ft_putchar_fd(c, 1);

    return (0);
}
*/
