#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int ft_is_all_white_spaces(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        //if (*s != 32 && (*s < 9 || *s > 13))
       if (s[i] != 32 && (s[i] < 9 || s[i] > 13))
		    return (0);
        i++;
    }
    return (1);
}


void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*ptr;

	count = 0;
	ptr = (char *)s;
	while (count < n)
	{
		ptr[count] = 0;
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	if (count && size && total / size != count)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

int	skip_word(char *str, int i)
{
	while (str[i] && str[i] != 32 && str[i] != 34 && str[i] != 39)
	{
		if (str[i] == '\\' && str[i + 1] != '\0')
			i += 2;
		else
			i++;
	}
	return (i);
}
int	skip_quotes(char *str, int i)
{
	char	quote;

	quote = str[i];
	i++;
	while (str[i] && str[i] != quote)
		i++;
	if (str[i] != quote)
	{
		printf("pipex: Missing %c\n", quote);
		exit (1);
	}
	return (i);
}

static int	count_words(char *command)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (command[i])
	{
		if (command[i] == 39 || command[i] == 34)
		{
			words++;
			i = skip_quotes(command, i) + 1;
		}
		else if (command[i] != 32)
		{
			words++;
			i = skip_word(command, i);
		}
		else
			i++;
	}
	return (words);
}

static char	*extract_word(char *command, int len)
{
	char	*word;
	int		i;
	int		j;

	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if ((command[0] == 34 || command[0] == 39) && command[i] == command[0])
			i++;
		else if (command[0] != 39 && command[0] != 34 && command[i] == 32)
			i++;
		else
		{
			if (command[0] != 39 && command[0] != 34 && command[i] == '\\')
				i++;
			word[j++] = command[i++];
		}
	}
	word[j] = '\0';
	int c;
	c = 0;
	while (word[c] != '\0')
	{
		c++;
	}
	printf("from subsub %d\n", c);
	return (word);
}

static char	**split_word(char *command, char **array, int words, int order)
{
	int		i;
	char	quote_char;
    //char *y = "abc";

	while (++order < words)
	{
		while (*command == 32)
			command++;
		i = 0;
		quote_char = *command;
		if (*command == 39 || *command == 34)
		// {
        //     i = skip_quotes(command, 0) + 1;
        // }
		{
			//while (command[++i] != quote_char)
			i = skip_quotes(command, 0) + 1;
		}		
		else
			i = skip_word(command, 0);
		array[order] = extract_word(command, i);
		if (!array[order])
		{
			//ft_free_triptr(&array);
			return (NULL);
		}
		if (*command == 39 || *command == 34)
			i++;
		command += i;
	}
	return (array);
}

char	**split_command(char *command)
{
	int		words;
	char	**array;

	if (!command || *command == '\0')
		return (NULL);
	if (ft_is_all_white_spaces(command))
        return (0);
		//handle_cmd_error(&command, "Command not found", 0);
	words = count_words(command);
	array = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	array = split_word(command, array, words, -1);
	return (array);
}

int main(int argc, char **argv)
{
    char	**splitted_cmd;

    if (argc == 2)
    {
        int i= 0;
        printf("from main argv1: %s\n", argv[1]);
        splitted_cmd = split_command(argv[1]);
        while (splitted_cmd[i] != NULL)
        {
            printf("command: %s\n", splitted_cmd[i]);
            i++;
        }
    }
    printf("\n");
}

// ./a.out '"""" lsaa """" aa bbbb''''bb  ' worked fine
// ./a.out """"" lsaa """" aa bbbb''''bb  " segfault 