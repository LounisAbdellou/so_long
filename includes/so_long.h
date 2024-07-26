/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:03:59 by labdello          #+#    #+#             */
/*   Updated: 2024/07/26 11:41:04 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"

# define WIDTH 1200
# define HEIGHT 700

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
}	t_env;

char	*get_next_line(int fd);
size_t	get_line_count(char *filename);

#endif
