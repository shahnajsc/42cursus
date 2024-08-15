/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:52:54 by shachowd          #+#    #+#             */
/*   Updated: 2024/08/15 12:45:04 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main()
{
	// int id1 = fork();
	// int id2 = fork();
	// if (id1 == 0)
	// {
	// 	printf("id1 f1: child %d\n", id1);
	// }
	// else
	// {
	// 	printf("id1 f1: parent  %d\n", id1);
	// }
	// if (id2 == 0)
	// {
	// 	printf("id2 f2: child %d\n", id2);
	// }
	// else
	// {
	// 	printf("id2 f2: parent  %d\n", id2);
	// }
	// printf("\n");
	
	int id1 = fork();
	int id2 = fork();
	int id3 = fork();
	int id4 = fork();
	printf("%d %d %d %d\n", id1, id2, id3, id4);
	printf("\n");
}