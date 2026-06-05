/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:36:09 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/05 18:29:24 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_offset_stash(char *stash, char *line)
{
	int	len;
	int	j;

	if (!stash || !line)
		return (stash);
	len = ft_strlen(line);
	if (stash[len] == '\0')
	{
		free (stash);
		return (NULL);
	}
	j = 0;
	while (stash[len + j])
	{
		stash[j] = stash[len + j];
		j++;
	}
	stash[j] = '\0';
	return (stash);
}

static char	*ft_extract(char *stash)
{
	char	*line;
	int		to_copy;
	int		i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	to_copy = 0;
	while (stash[to_copy] && stash[to_copy] != '\n')
		to_copy++;
	if (stash[to_copy] == '\n')
		to_copy++;
	line = malloc(sizeof(char) * (to_copy + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < to_copy)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_fill_stash(int fd, char *buffer, char *stash)
{
	ssize_t	bytes_read;

	if (!stash)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_gnl_strjoin(stash, buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_fill_stash(fd, buffer, stash);
	free(buffer);
	if (!stash)
		return (NULL);
	line = ft_extract(stash);
	stash = ft_offset_stash(stash, line);
	if (!line)
    {
        if (stash)
        {
            free(stash);
            stash = NULL;
        }
        return (NULL);
    }
	return (line);
}

/* 
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	stash = ft_fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract(stash);
	stash = ft_offset_stash(stash, line);
	if (!line)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	return (line);
}
 */

/* 
static char	*ft_offset_stash(char *stash)  // wie mem_move
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	if (!stash[i + 1])
		return (free(stash), NULL);
	new_stash = malloc(sizeof(char) * (ft_strlen(stash + i + 1) + 1));  
	  malloc braucht man hier nicht
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
 */
/* 
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test3.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
 */