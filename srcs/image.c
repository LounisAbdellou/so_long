/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:00:04 by labdello          #+#    #+#             */
/*   Updated: 2024/07/31 10:00:55 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	init_images(t_env *env)
{
	int		w;
	int		h;
	int		i;
	void	**img_tab;

	i = 0;
	w = 32;
	h = 32;
	img_tab = malloc(sizeof(void *) * 9);
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
}

void	draw_map(t_env *env)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_images(env);
	while (env->map[i] != NULL)
	{
		j = 0;
		while (env->map[i][j] != '\0')
		{
			mlx_put_image_to_window(env->mlx, env->win, env->img[floor_i], j * 32, i * 32);
			j++;
		}
		i++;
	}
}
