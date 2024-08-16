/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:03:59 by labdello          #+#    #+#             */
/*   Updated: 2024/08/16 18:13:46 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"

# ifndef PATH
#  define PATH "."
# endif

# define FLOOR "/assets/sprites/floor.xpm" 
# define WALL "/assets/sprites/wall.xpm"
# define COIN "/assets/sprites/coin-bag.xpm"
# define EXIT_O "/assets/sprites/open-exit.xpm"
# define EXIT_C "/assets/sprites/exit-closed.xpm"
# define PLAYER_UP "/assets/sprites/player/back.xpm"
# define PLAYER_DOWN "/assets/sprites/player/front.xpm"
# define PLAYER_LEFT "/assets/sprites/player/left.xpm"
# define PLAYER_RIGHT "/assets/sprites/player/right.xpm"

typedef enum e_param
{
	wall = '1',
	floor = '0',
	item = 'C',
	end = 'E',
	start = 'P',
}	t_param;

typedef enum e_img
{
	floor_i = 0,
	wall_i = 1,
	coin_i = 2,
	open_i = 3,
	close_i = 4,
	p_up = 5,
	p_down = 6,
	p_left = 7,
	p_right = 8,
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	**img;
	char	**map;
	int		screen_w;
	int		screen_h;
	t_point	current_pos;
	int		is_open;
}	t_env;

int		destroy(t_env *env);
int		handle_keydown(int keycode, t_env *env);
int		move_character(t_env *env, char direction);
char	*sanitize_line(char *line);
void	check_img(t_env *env);
void	init_env(t_env *env);
void	init_start_pos(t_env *env);
void	init_images(t_env *env, void **img_tab);
void	flood(t_env *env);
void	draw_map(t_env *env);
void	check_map(t_env *env);
void	free_img_tab(t_env *env);
void	check_file(char *filepath, t_env *env);
void	put_image(t_env *env, char img_type, size_t x, size_t y);
void	return_error(char *error_message, int exit_status, t_env *env);

#endif
