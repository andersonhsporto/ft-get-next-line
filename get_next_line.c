#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


static char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	i;

	string = malloc(ft_strlen(s1) + 1);
	if (string == 0)
		return (0);
	else
	{
		i = 0;
		while (i < (ft_strlen (s1) + 1))
		{
			string[i] = s1[i];
			i++;
		}
	}
	return (string);
}

static char	*get_line(char **buffer_backup)
{
	char	*line;
	char	*temp;
	ssize_t	i;

	i = 0;
	while (((*buffer_backup)[i] != 10) && ((*buffer_backup)[i] != '\0'))
		i++;
	if ((*buffer_backup)[i] == 0)
	{
		line = ft_strdup(*buffer_backup);
		free(*buffer_backup);
		*buffer_backup = NULL;
	}
	else
	{
		line = ft_substr(*buffer_backup, 0, i + 1);
		temp = ft_strdup(&(*buffer_backup)[i + 1]);
		free(*buffer_backup);
		*buffer_backup = 0;
		if (*temp)
			*buffer_backup = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	return (line);
}

char	*get_next(int fd, char **static_buff, char **temp_buff)
{
	char	*line;
	int	bytes_read;

	bytes_read = read(fd, *temp_buff, (BUFFER_SIZE));
	while (bytes_read > 0)
	{
		(*temp_buff)[bytes_read] = '\0';
		line = (ft_strdup(*static_buff));
		free(*static_buff);
		*static_buff = ft_strjoin(line, *temp_buff);
		free(line);
		line = NULL;
		bytes_read = read(fd, *temp_buff, (BUFFER_SIZE));
	}
	free(*temp_buff);
	*temp_buff = NULL;
	if (bytes_read == 0 && ((*static_buff)[0] == '\0'))
	{
		return (NULL);
	}
	return (get_line(static_buff));
}

char	*get_next_line(int fd)
{
	static char	*static_buff = NULL;
	char		*temp_buff;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	temp_buff = malloc((BUFFER_SIZE + 1));
	if (!temp_buff)
		return (NULL);
	if (read(fd, temp_buff, 0) < 0)
	{
		free(temp_buff);
		temp_buff = NULL;
		return (NULL);
	}
	if (static_buff == NULL)
		static_buff = ft_strdup("");
	return (get_next(fd, &static_buff, &temp_buff));
}
/* 
#include <stdio.h>
#include <time.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

    clock_t t;
    t = clock();
	fd1 = open("text.txt", O_RDONLY);
	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("gnl() took %f seconds to execute \n", time_taken);
	return (0);
}
 */