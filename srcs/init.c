/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:32:19 by labdello          #+#    #+#             */
/*   Updated: 2024/08/16 17:37:18 by labdello         ###   ########.fr       */
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

void	*alloc_image(void *mlx, char *relative_path)
{
	int		w;
	int		h;
	char	*absolute_path;
	void	*img_ptr;

	w = 32;
	h = 32;
	absolute_path = ft_strjoin(PATH, relative_path);
	img_ptr = mlx_xpm_file_to_image(mlx, absolute_path, &w, &h);
	free(absolute_path);
	return (img_ptr);
}

void	init_images(t_env *env, void **tab)
{
	tab[floor_i] = alloc_image(env->mlx, FLOOR);
	tab[wall_i] = alloc_image(env->mlx, WALL);
	tab[coin_i] = alloc_image(env->mlx, COIN);
	tab[open_i] = alloc_image(env->mlx, EXIT_O);
	tab[close_i] = alloc_image(env->mlx, EXIT_C);
	tab[p_up] = alloc_image(env->mlx, PLAYER_UP);
	tab[p_down] = alloc_image(env->mlx, PLAYER_DOWN);
	tab[p_left] = alloc_image(env->mlx, PLAYER_LEFT);
	tab[p_right] = alloc_image(env->mlx, PLAYER_RIGHT);
}
