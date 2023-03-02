
#include "./get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char *buffer, int bytes)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	output = malloc(sizeof(char) * (ft_strlen(storage) + bytes + 1));
	if (!output)
		return (NULL);
	if (storage != NULL)
	{
		output[i] = storage[i];
		i++;
	}
	while (bytes > j)
	{
		output[i] = buffer[j];
		i++;
		j++;
	}
	output[i] = '\0';
	if (storage)
	{
		free(storage);
		storage = NULL;
	}
	return (output);
}

int	ft_strchr(char *storage, char c)
{
	int	i;

	i = 0;
	if (!storage)
		return (0);
	while (storage[i] != '\0')
	{
		if (storage[i] == c)
			return (1);
		i++;
	}
	if (storage[i] == '\0')
		return (2);
	else
		return (0);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_output (char *storage)
{

}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;
	char	*storage;
	char	*next_line;

	if (BUFFER_SIZE < 0 || fd < 0 || fd > 999)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		storage = ft_strjoin(storage, buffer, bytes);
		if (bytes < BUFFER_SIZE || ft_strchr(storage, '\n') == 1)
			break ;
	}
	next_line = ft_output (&storage);
	if (ft_strlen(next_line) == 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	return (next_line);
}
