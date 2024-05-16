/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:30:23 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/16 14:15:40 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			count;
	int			signcount;
	long int	number;
	long int	check;

	count = 0;
	signcount = 1;
	number = 0;
	while ((str[count] >= 9 && str[count] <= 13) || (str[count] == 32))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			signcount = -1;
		count++;
	}
	while (str[count] >= 48 && str[count] <= 57)
	{
		check = (number * 10) + str[count] - 48;
		if (check / 10 != number && signcount == -1)
			return (0);
		if (check / 10 != number && signcount == 1)
			return (-1);
		number = check;
		count++;
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
