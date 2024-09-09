/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:25:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/09 17:26:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *quoted_word(char *cmd)
{
	char value;

	value = *(cmd - 1);
	printf("begin frm q_qord %s\n", cmd);
	while (*cmd && *cmd != 34)
		cmd++;
	printf("frm q_qord after increase %s\n", cmd);
	if (*cmd != value || *cmd == '\0') // ((cmd[i] && cmd[i] != value) || cmd[i] == '\0')
	{
					//error_return("cmd_split", "cmd", 1);
		printf("\nquootes missing\n");
		exit(1);
	}
	//char value;

	// while (cmd[index] != '\0')
	// {
	// 	while (cmd[index] && cmd[index] != value)
	// 		index++;
	// 	if (cmd[index] != value || cmd[index] == '\0') // ((cmd[i] && cmd[i] != value) || cmd[i] == '\0')
	// 	{
	// 		//error_return("cmd_split", "cmd", 1);
	// 		printf("\nquootes missing\n");
	// 		exit(1);
	// 	}
	// 	else
	// 		index++;				
	// }
	return (cmd);
}

char *normal_word(char *cmd)
{
	printf("begin n_word %s\n", cmd);
	if (*cmd && *cmd != 34 && *cmd != 39 && *cmd == 92 )
		cmd = cmd+2;
	printf("n_word %s\n", cmd);
	while (*cmd && *cmd != 34 && *cmd != 39 && *cmd != 32)
		cmd++;
	// while (cmd[index] && cmd[index] != 34 && cmd[index] != 39 && cmd[index] != 32)
	// {
	// 	if (cmd[index] && cmd[index] != 34 && cmd[index] != 39 && cmd[index] == 92 )
	// 		index = index+2;
	// 	else
	// 		index++;
	// }
	return (cmd);
}

static int count_words(char *cmd)
{
	int count;

	count = 0;
	while (*cmd != '\0')
	{
		while (*cmd && *cmd == 32)
			cmd++;
		printf("after sp %s\n", cmd);
		if (*cmd && (*cmd == 34 || *cmd == 39 ))
		{
	 		printf("after first q increase %s\n", cmd);
			if (*cmd && *cmd == *(cmd - 1))
			{
				cmd++;
				printf("after second q increase %s\n", cmd);
			}
			else if ((*cmd == 34 || *cmd == 39) && *cmd != *(cmd - 1))
			{
				count++;
				cmd = quoted_word(cmd);			
			}
		}
		else if (*cmd && *cmd != 32)
		{
			 count++;
			 cmd = normal_word(cmd);		
		}		
	}
	return (count);
} 

int main(int argc, char **argv)
{
    
    if (argc == 2)
    {
        printf("\nfrom main argv1: %s\n", argv[1]);
		printf("counts from main: %d\n",  count_words(argv[1]));
    }
	else
    	printf("\nmore arguments\n");
	printf("\n");
}
// static int count_words(char *cmd)
// {
// 	int count;
// 	int i;

// 	count = 0;
// 	i = 0;
// 	while (cmd[i] != '\0')
// 	{
// 		while (cmd[i] && cmd[i] == 32)
// 			i++;
// 		if (cmd[i] && (cmd[i] == 34 || cmd[i] == 39 ))
// 		{
// 			if (cmd[i] && (cmd[i + 1] == cmd[i]))
// 				i = i+2;
// 			else if ((cmd[i + 1] == 34 || cmd[i - 1] == 39) && (cmd[i] != cmd[i - 1]))
// 			{
// 				count++;
// 				i = quoted_word(cmd, i);			
// 			}
// 		}
// 		else if (cmd[i] && cmd[i] != 32)
// 		{
// 			 count++;
// 			 i = normal_word(cmd, i);		
// 		}		
// 	}
// 	return (count);
// } 