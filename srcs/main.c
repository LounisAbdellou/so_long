/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:01:50 by labdello          #+#    #+#             */
/*   Updated: 2024/07/26 17:45:49 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_env	init_env(char *filepath)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, filepath);
	if (!env.win)
		return_error("Error initializing window\n", 1, &env);
	env.map = NULL;
	return (env);
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
	env->map[line_count] = NULL;
	while (line != NULL)
	{
		env->map[i] = sanitize_line(line);
		line = get_next_line(fd);
		i++;
	}
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
	handle_file_parse(fd, get_line_count(av[1]), &env);
	mlx_hook(env.win, 2, 1L << 0, handle_keydown, &env);
	mlx_hook(env.win, 17, 1L << 0, destroy, &env);
	mlx_loop(env.mlx);
	return (0);
}
