/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:31:37 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/04 09:33:01 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_adv(char *copy, char *original, int content)
{
	int	i;

	i = 0;
	while (i < content)
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
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

char	*ft_strcpy_join(char *dst, const char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	char	*ptr;

	if (!s1 || !s2)		//TODO Ich würd wenn eins von den beiden NULL ist eher strdup vom anderen returnen
		return (0);
	jstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (jstr == 0)
		return (0);
	ptr = ft_strcpy_join(jstr, s1);
	ft_strcpy_join(ptr, s2);
	return (jstr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (dest == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (*s++)
	{
		c++;
	}
	return (c);
}
