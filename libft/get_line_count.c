/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:54:41 by labdello          #+#    #+#             */
/*   Updated: 2024/07/28 09:04:40 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_line_count(int fd)
{
	size_t	count;

	count = 0;
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}
