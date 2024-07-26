/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:01:50 by labdello          #+#    #+#             */
/*   Updated: 2024/07/26 13:03:08 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_env *env)
{
	if (env->map != NULL)
		ft_free_tab(env->map);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(1);
}

int	handle_keydown(int keycode, t_env *env)
{
	if (keycode == 65307)
		return (destroy(env));
	return (0);
}

int	handle_file_parse(int fd, size_t line_count, t_env *env)
{
	size_t	i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	env->map = malloc(sizeof(char *) * (line_count + 1));
	if (!env->map)
		return (0);
	env->map[line_count] = NULL;
	while (line != NULL)
	{
		env->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

t_env	init_env(char *filename)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, filename);
	// if (!env->win)
	// 	ft_return_error("error initializing window", 1);
	
	return (env);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (1);
	env = init_env(av[1]);
	mlx_hook(env.win, 2, 1L<<0, handle_keydown, &env);
	mlx_hook(env.win, 17, 1L<<0, destroy, &env);
	if (!handle_file_parse(open(av[1], O_RDONLY), get_line_count(av[1]), &env))
		return (1);
	for (int i = 0; env.map[i] != NULL; i++)
	{
		for (int j = 0; env.map[i][j] != '\0'; j++)
			printf("%c ", env.map[i][j]);
		printf("\n");
	}
	mlx_loop(env.mlx);
	return (0);
}
