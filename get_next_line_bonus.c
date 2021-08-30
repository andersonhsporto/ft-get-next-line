/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:35:44 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/30 14:01:09 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char **buffer_backup, size_t i)
{
	char	*line;
	char	*temp;

	while (((*buffer_backup)[i] != '\n') && ((*buffer_backup)[i] != '\0'))
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
		*buffer_backup = NULL;
		if (*temp)
			*buffer_backup = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	return (line);
}

char	*get_next(int fd, ssize_t bytes_read, char *temp_buff)
{
	static char	*s_buffer[256];
	char		*temp;

	while (bytes_read > 0)
	{
		temp_buff[bytes_read] = '\0';
		if (s_buffer[fd] == 0)
			s_buffer[fd] = ft_strdup("");
		temp = ft_strdup(s_buffer[fd]);
		free(s_buffer[fd]);
		s_buffer[fd] = ft_strjoinfree(temp, temp_buff);
		if (ft_strchr(s_buffer[fd], '\n'))
			break ;
		bytes_read = read(fd, temp_buff, BUFFER_SIZE);
	}
	if (bytes_read == 0 && s_buffer[fd] == 0)
		return (NULL);
	return (get_line(&s_buffer[fd], 0));
}

char	*get_next_line(int fd)
{
	char		temp_buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if ((fd < 0) || (BUFFER_SIZE < 1) || (read(fd, temp_buff, 0) < 0))
		return (NULL);
	bytes_read = read(fd, temp_buff, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	return (get_next(fd, bytes_read, temp_buff));
}
