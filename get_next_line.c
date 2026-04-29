/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:36:09 by lschawer          #+#    #+#             */
/*   Updated: 2026/04/29 15:56:55 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char    *ft_update_stash(char *old_stash)
{
    // Update the Stash: 
    // Re-save the leftovers into the static variable for next time.
    char    *updated_stash;
    int     i;
    int     k;
    
    i = 0;
    while (old_stash[i] && old_stash[i] != '\n')
        i++;
    if (!old_stash[i] || !old_stash[i + 1])
    {
        free(old_stash);
        return (NULL);
    }
    updated_stash = malloc(sizeof(char) * (ft_strlen(old_stash + i +1) + 1));
    if (!updated_stash)
    {
        free (old_stash);
        return (NULL);
    }
    i++;
    while (old_stash[i])
        updated_stash[k++] = old_stash[i++];
    updated_stash[k] = '\0';
    free (old_stash);
    return (updated_stash);
}

char    *ft_strcpy_adv(char *copy, char *original, int content)
{
    int i;

    i = 0;
    while (i < content)
    {
        copy[i] = original[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *ft_extract(char *str)
{
    char    *line;
    int     to_copy;
    int     i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        to_copy = i + 1;
    else
        to_copy = i;
    line = malloc(sizeof(char) * (to_copy + 1));
    if (!line)
        return (NULL);
    ft_strcpy_adv(line, str, to_copy);
    return (line);
}

char    *ft_fill_stash(int fd, void *buffer, size_t buf_size, char *stash)
{
    ssize_t     bytes_read;
    char        *tmp;

    bytes_read = 1;
    while (!ft_strchr(stash, 10) && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, buf_size);
        if (bytes_read == -1)
        {
            free (stash)
            stash = NULL;
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        tmp = stash;
        stash = ft_strjoin(stash, buffer);
        if (!stash)
            return (NULL);
        free(tmp);
    }
    return (stash);
}

char    *ft_read_one_line(int fd, void *buffer, size_t buf_size)
{
    char        *line;
    static char *stash;

    if (!stash)
    {
        stash = ft_strdup("");
        if (!stash)
            return (NULL);
    }
    stash = ft_fill_stash(fd, buffer, buf_size, stash);
    if (!stash || *stash == "\0")
    {
        free (stash);
        stash = NULL;
        return (NULL);
    }
    line = ft_extract(stash);
    stash = ft_update_stash(stash);
    return (line);
}

char    *get_next_line(int fd)
{
    ssize_t bytes_read;
    void *buffer;
    char *line;

    // error checks
    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!readbuf)
        return (NULL);
    line = ft_read_one_line(fd, buffer, BUFFER_SIZE);
    free (buffer);
    return (line);
}
