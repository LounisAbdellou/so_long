/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:01:50 by labdello          #+#    #+#             */
/*   Updated: 2024/07/31 16:16:07 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	mlx_get_screen_size(env->mlx, &env->screen_w, &env->screen_h);
	env->screen_h = env->screen_h - 37;
	env->win = NULL;
	env->map = NULL;
	env->img = NULL;
}

void	init_start_pos(t_env *env)
{
	size_t	i;
	size_t	j;
	t_point	s_pos;

	if (env->map == NULL)
		return ;
	i = 0;
	while (env->map[i] != NULL)
	{
		j = 0;
		while (env->map[i][j] != '\0')
		{
			if (env->map[i][j] == start)
			{
				s_pos.x = j;
				s_pos.y = i;
				env->start_pos = s_pos;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	free_img_tab(t_env *env)
{
	size_t	i;

	i = 0;
	while (i <= 9)
	{
		if (env->img[i] != NULL)
			mlx_destroy_image(env->mlx, env->img[i]);
		i++;
	}
}
void	init_images(t_env *env, void **img_tab)
{
	int		w;
	int		h;
	int		i;

	i = 0;
	w = 32;
	h = 32;
	img_tab[floor_i] = mlx_xpm_file_to_image(env->mlx, FLOOR, &w, &h);
	img_tab[wall_i] = mlx_xpm_file_to_image(env->mlx, WALL, &w, &h);
	img_tab[coin_i] = mlx_xpm_file_to_image(env->mlx, COIN, &w, &h);
	img_tab[open_i] = mlx_xpm_file_to_image(env->mlx, EXIT_O, &w, &h);
	img_tab[close_i] = mlx_xpm_file_to_image(env->mlx, EXIT_C, &w, &h);
	img_tab[p_up] = mlx_xpm_file_to_image(env->mlx, PLAYER_UP, &w, &h);
	img_tab[p_down] = mlx_xpm_file_to_image(env->mlx, PLAYER_DOWN, &w, &h);
	img_tab[p_left] = mlx_xpm_file_to_image(env->mlx, PLAYER_LEFT, &w, &h);
	img_tab[p_right] = mlx_xpm_file_to_image(env->mlx, PLAYER_RIGHT, &w, &h);
	env->img = img_tab;
	while (i <= 9)
	{
		if (env->img[i] == NULL)
			return (free_img_tab(env));
		i++;
	}
	env->img = img_tab;
}

void	handle_file_parse(int fd, size_t line_count, t_env *env)
{
	size_t	i;
	char	*line;

	i = 0;
	if (line_count < 2)
		return_error("Map shape should be rectangular\n", 1, env);
	line = get_next_line(fd);
	if (!line)
		return_error("Could not read given file\n", 1, env);
	env->map = malloc(sizeof(char *) * (line_count + 1));
	if (!env->map)
		return_error("Memory allocation went wrong\n", 1, env);
	*env->map = NULL;
	while (line != NULL)
	{
		env->map[i] = sanitize_line(line);
		line = get_next_line(fd);
		i++;
	}
	env->map[i] = NULL;
	init_start_pos(env);
	check_map(env);
	close(fd);
}

void	so_long(char *filepath, t_env *env)
{
	size_t	win_w;
	size_t	win_h;

	win_w = ft_strlen(env->map[0]) * 32;
	win_h = ft_tablen(env->map) * 32;
	env->win = mlx_new_window(env->mlx, win_w, win_h, filepath);
	if (!env->win)
		return_error("Error initializing window\n", 1, env);
	mlx_hook(env->win, 2, 1L << 0, handle_keydown, env);
	mlx_hook(env->win, 17, 1L << 0, destroy, env);
	draw_map(env);
	mlx_loop(env->mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	t_env	env;
	void	*img_tab[9];

	init_env(&env);
	init_images(&env, img_tab);
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return_error("Wrong number of arguments\n", 1, &env);
	check_file(av[1], &env);
	handle_file_parse(fd, get_line_count(open(av[1], O_RDONLY)), &env);
	so_long(av[1], &env);
	return (0);
}
