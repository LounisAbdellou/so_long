/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:03:59 by labdello          #+#    #+#             */
/*   Updated: 2024/07/26 17:46:07 by labdello         ###   ########.fr       */
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

int		destroy(t_env *env);
int		handle_keydown(int keycode, t_env *env);
char	*get_next_line(int fd);
char	*sanitize_line(char *line);
size_t	get_line_count(char *filepath);
void	check_map(t_env *env);
void	check_file(char *filepath, t_env *env);
void	return_error(char *error_message, int exit_status, t_env *env);

#endif
