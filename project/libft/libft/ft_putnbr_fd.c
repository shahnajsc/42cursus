/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:19:34 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/29 15:29:04 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}
/*
//ft_putnbr(-2147483648);

#include <fcntl.h>
int main(void)
{
	int	n = 1232423;
	int file;

	file = open("putnbr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(n, file);
	close(file);
    
    n = 0253411;
    ft_putnbr_fd(n, 2);

    return (0);
}

*/
