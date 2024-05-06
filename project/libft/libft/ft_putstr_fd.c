/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:46:54 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/29 14:02:17 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write(fd, s++, 1);
	}
}
/*

#include <fcntl.h>
int main(void)
{
	char *s = "abcDEF";
	int file;

	file = open("putstr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd(s, file);
	close(file);
    
    s = "12345ERT";
    ft_putstr_fd(s, 1);

    return (0);
}
*/
