/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:00:04 by labdello          #+#    #+#             */
/*   Updated: 2024/07/30 19:56:11 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_env *env)
{
	void	img_tab[9];

	img_tab[floor_i] = mlx_xpm_file_to_image(env->mlx, FLOOR, 32, 32);
	img_tab[wall_i] = mlx_xpm_file_to_image(env->mlx, WALL, 32, 32);
	img_tab[coin_i] = mlx_xpm_file_to_image(env->mlx, COIN, 32, 32);
	img_tab[open_i] = mlx_xpm_file_to_image(env->mlx, EXIT_O, 32, 32);
	img_tab[close_i] = mlx_xpm_file_to_image(env->mlx, EXIT_C, 32, 32);
	img_tab[p_up] = mlx_xpm_file_to_image(env->mlx, PLAYER_UP, 32, 32);
	img_tab[p_down] = mlx_xpm_file_to_image(env->mlx, PLAYER_DOWN, 32, 32);
	img_tab[p_left] = mlx_xpm_file_to_image(env->mlx, PLAYER_LEFT, 32, 32);
	img_tab[p_right] = mlx_xpm_file_to_image(env->mlx, PLAYER_RIGHT, 32, 32);
	env->img = img_tab;
}

void	draw_map(t_env *env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (env->map[i] != NULL)
	{
		j = 0;
		while (env->map[i][j] != '\0')
		{
			// mlx_put_image_to_window(*mlx_ptr, *win_ptr, *img_ptr, x, y);
			j++;
		}
		i++;
	}
}
