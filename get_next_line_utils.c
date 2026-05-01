/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:31:37 by lschawer          #+#    #+#             */
/*   Updated: 2026/05/01 18:38:34 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

