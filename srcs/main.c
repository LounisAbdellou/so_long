/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:01:50 by labdello          #+#    #+#             */
/*   Updated: 2024/07/30 16:47:48 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_env	init_env(char *filepath)
{
	t_env	env;
	int		width;
	int		height;

	env.mlx = mlx_init();
	mlx_get_screen_size(env.mlx, &width, &height);
	env.win = mlx_new_window(env.mlx, width / 2, height - 37, filepath);
	if (!env.win)
		return_error("Error initializing window\n", 1, &env);
	env.map = NULL;
	env.start_pos = NULL;
	return (env);
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
				env->start_pos = &s_pos;
				return ;
			}
			j++;
		}
		i++;
	}
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

int	main(int ac, char **av)
{
	int		fd;
	t_env	env;

	fd = open(av[1], O_RDONLY);
	env = init_env(av[1]);
	if (ac != 2)
		return_error("Wrong number of arguments\n", 1, &env);
	check_file(av[1], &env);
	handle_file_parse(fd, get_line_count(open(av[1], O_RDONLY)), &env);
	mlx_hook(env.win, 2, 1L << 0, handle_keydown, &env);
	mlx_hook(env.win, 17, 1L << 0, destroy, &env);
	mlx_loop(env.mlx);
	return (0);
}
