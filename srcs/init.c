/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:32:19 by labdello          #+#    #+#             */
/*   Updated: 2024/08/05 16:32:56 by labdello         ###   ########.fr       */
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
	env->is_open = 0;
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
				env->current_pos = s_pos;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_images(t_env *env, void **img_tab)
{
	int		w;
	int		h;

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
}
