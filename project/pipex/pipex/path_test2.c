
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


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
	return (word);
}

static char	**split_word(char *command, char **array, int words, int order)
{
	int		i;
	char	quote_char;

	while (++order < words)
	{
		while (*command == 32)
			command++;
		i = 0;
		quote_char = *command;
		if (*command == 39 || *command == 34)
			while (command[++i] != quote_char)
				;
		else
			i = skip_word(command, 0);
		array[order] = extract_word(command, i);
		if (!array[order])
		{
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

	if (!command)
		return (NULL);
	words = count_words(command);
	array = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	array = split_word(command, array, words, -1);
	return (array);
}