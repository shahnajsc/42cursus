/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:52:54 by shachowd          #+#    #+#             */
/*   Updated: 2024/08/21 11:53:59 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <error.h>

int pipex()
{
	
}


int main(int argc, char **argv, char **envp)
{
	char *msg = "test fd stdout\n";
	int r;
	
	if (argc != 5)
	{
		printf("Wrong command format\nCorrect format: \"infile cmd1 cmd2 outfile\"\n)");
		return (1);
	}
	else
	{
		r = write(0, msg, strlen(msg));
		printf("%d\n", r);
		perror("test ");
	}
    return 0;
	
}