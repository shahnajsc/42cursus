/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:52:54 by shachowd          #+#    #+#             */
/*   Updated: 2024/08/29 09:51:31 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	pid_wait(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (5);
}

int pipex()
{
	int i;
	int status;
	pid_t pid[2];

	i = -1;
	while ((++i) < 2)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			printf("error in forking");
		}
		if(pid[i] != 0)
		{
			printf("parent id: %d  i :  %d\n", pid[i], i);
		}
	}
	close(pid[i]);
	i = -1;
	while ((++i) < 2)
		status = pid_wait(pid[i]);
	return (status);
}


int main(int argc, char **argv, char **envp)
{
	int pip_stat;
	
	if (argc != 5)
	{
		printf("Wrong command format\nCorrect format: \"infile cmd1 cmd2 outfile\"\n");
		return (1); // need to return actual error number ****
	}
	else
	{
		pip_stat = pipex();
		printf("\nstatus print: %d\n", pip_stat); // remove before submission 
	}
    return 0;
	
}