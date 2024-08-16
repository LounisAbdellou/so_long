/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:01:50 by labdello          #+#    #+#             */
/*   Updated: 2024/08/16 17:51:38 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (win_w > (size_t)env->screen_w || win_h > (size_t)env->screen_h)
		return_error("The map is too big\n", 1, env);
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

	ft_printf("%s\n", PATH);
	*img_tab = NULL;
	fd = open(av[1], O_RDONLY);
	init_env(&env);
	init_images(&env, img_tab);
	env.img = img_tab;
	check_img(&env);
	if (ac != 2)
		return_error("Wrong number of arguments\n", 1, &env);
	check_file(av[1], &env);
	handle_file_parse(fd, get_line_count(open(av[1], O_RDONLY)), &env);
	so_long(av[1], &env);
	return (0);
}
