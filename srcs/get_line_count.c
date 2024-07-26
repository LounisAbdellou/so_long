/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:54:41 by labdello          #+#    #+#             */
/*   Updated: 2024/07/26 11:32:20 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 5

size_t	get_line_count(char *filename)
{
	ssize_t	i;
	ssize_t	count;
	int		fd;
	char	buffer[BUFFER_SIZE];

	count = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		i = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	close(fd);
	return (count);
}
