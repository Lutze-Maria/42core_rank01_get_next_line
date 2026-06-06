/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:14:43 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/06 10:01:41 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef DELIMITER
#  define DELIMITER '\n'
# endif

# include <stdlib.h>
# include <unistd.h>

// main logic function
char	*get_next_line(int fd);

// utility functions
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_rest(char *jstr, char const *buffer, size_t i);
char	*ft_gnl_strjoin(char *stash, char const *buffer);
char	*ft_strdup(const char *s);

#endif