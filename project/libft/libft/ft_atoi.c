/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:30:23 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/16 15:47:38 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			signcount;
	long int	number;
	long int	check;

	signcount = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signcount = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		check = (number * 10) + *str - 48;
		if (check / 10 != number && signcount == -1)
			return (0);
		if (check / 10 != number && signcount == 1)
			return (-1);
		number = check;
		str++;
	}
	return (number * signcount);
}
/*
int main(void)
{
	char *str;

	str = "++--+-+-54321ad656";
	printf("from the ft function: %d\n", ft_atoi("   ---47a"));
	printf("from the lib function: %d\n", atoi("   ---47a")); 
		// while (str[count])
	// {
	// 	if (str[count] < 48 || str[count] > 57)
	// 		break ;
	// 	else
	// 		number = (number * 10) + str[count] - 48;
	// 	count++;
	// }
}
*/
