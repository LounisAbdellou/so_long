/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:00:04 by labdello          #+#    #+#             */
/*   Updated: 2024/08/04 11:52:12 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_env *env, char img_type, size_t x, size_t y)
{
	if (img_type == floor)
		mlx_put_image_to_window(env->mlx, env->win, env->img[floor_i], x, y);
	else if (img_type == wall)
		mlx_put_image_to_window(env->mlx, env->win, env->img[wall_i], x, y);
	else if (img_type == item)
		mlx_put_image_to_window(env->mlx, env->win, env->img[coin_i], x, y);
	else if (img_type == start)
		mlx_put_image_to_window(env->mlx, env->win, env->img[p_right], x, y);
	else if (img_type == end)
		mlx_put_image_to_window(env->mlx, env->win, env->img[close_i], x, y);
	else if (img_type == 'U')
		mlx_put_image_to_window(env->mlx, env->win, env->img[p_up], x, y);
	else if (img_type == 'D')
		mlx_put_image_to_window(env->mlx, env->win, env->img[p_down], x, y);
	else if (img_type == 'L')
		mlx_put_image_to_window(env->mlx, env->win, env->img[p_left], x, y);
	else if (img_type == 'R')
		mlx_put_image_to_window(env->mlx, env->win, env->img[p_right], x, y);
	else if (img_type == 'O')
		mlx_put_image_to_window(env->mlx, env->win, env->img[open_i], x, y);
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
			put_image(env, env->map[i][j], j * 32, i * 32);
			j++;
		}
		i++;
	}
}
