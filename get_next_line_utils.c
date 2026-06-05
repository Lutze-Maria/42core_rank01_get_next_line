/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:12:55 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/05 18:04:34 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s) //TO DO: adaptieren: bis deliminator
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_rest(char *jstr, char const *buffer, size_t i)
{
	size_t	j;

	j = 0;
	while (buffer[j])
	{
		jstr[i + j] = buffer[j];
		j++;
	}
	jstr[i + j] = '\0';
	return (jstr);
}

char	*ft_gnl_strjoin(char *stash, char const *buffer)
{
	char	*jstr;
	size_t	i;

	if (!stash)
		return (ft_strdup(buffer));
	if (!buffer)
		return (ft_strdup(stash));
	jstr = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (jstr == 0)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i])
	{
		jstr[i] = stash[i];
		i++;
	}
	ft_strjoin_rest(jstr, buffer, i);
	free(stash);
	return (jstr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/* 
char	*ft_strcpy(char *dst, const char *src)
{
	char	*start;

	start = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (start);
}
 */