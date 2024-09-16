#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// int ft_len(char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
int count_cmd_parts(char *cmd)
{
	int count;
	int i;
	
	count = 0;
	i = 0;
	if (!cmd || !*cmd)
		return (0);
	while (cmd[i] != '\0')
	{
		if (cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != '\0')
		{
			count++;
		}
		while (cmd[i] == ' ' || cmd[i] == '\t')
		{
			if (cmd[i + 1] != ' ' && cmd[i + 1] != '\t' && cmd[i + 1] != '\0')
				count++;
			i++;
		}
		i++;
	}
	printf("srting: %s\n", cmd);
	return (count);
}
// char *get_cmd_part(char **cmd_splitted, int cmd_count)
// {

// }

void command_split(char *cmd)
{
	//char **cmd_splitted;
	int cmd_count;
	//int i;

	cmd_count = 0;
	//i = 0;
	if (!cmd || !*cmd)
		return ; // error msg
	cmd_count = count_cmd_parts(cmd);
	printf("total words %d \n", cmd_count);
	
}
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		command_split(argv[1]);
	}
	printf ("\n");
}