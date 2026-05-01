/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:42:39 by lschawer          #+#    #+#             */
/*   Updated: 2026/05/01 18:37:23 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);




char	*ft_update_stash(char *old_stash);
char	*ft_strcpy_adv(char *copy, char *original, int content);
char	*ft_extract(char *str);
char	*ft_fill_stash(int fd, void *buffer, size_t buf_size, char *stash);
char	*ft_read_one_line(int fd, void *buffer, size_t buf_size);

#endif