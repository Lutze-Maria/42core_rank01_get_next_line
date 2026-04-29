


char    *ft_update_stash(char *str)
{
    // Update the Stash: 
    // Re-save the leftovers into the static variable for next time.
    while (stash[i])
    {
        if (stash[i] == "\n")
        {
            
        }
        i++;
    }
}

ft_strcpy_adv(char *copy, char *original, int len)
{
    int i;

    i = 0;

}

char    *ft_extract(char *str)
{
    /*Check: looks at the static stash, finds the \n,
    Output:  Extract the Line: Create a new string that stops at the \n.
    */

    char    *line;
    int     i;
    int     len;

    i = 0;
    while (stash[i])
    {
        if (stash[i] == "\n")
        {
            len = i + 1;
            line = malloc(sizeof(char) * (len + 1));
            ft_strcpy_adv(line, stash, i);
        }
        i++;
    }
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


char *get_next_line(int fd)
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
