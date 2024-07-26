/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:40:36 by labdello          #+#    #+#             */
/*   Updated: 2024/07/26 16:04:23 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_env *env)
{
	if (env->map != NULL)
		ft_free_tab(env->map);
	if (env->win != NULL)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx != NULL)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	exit(1);
}

int	handle_keydown(int keycode, t_env *env)
{
	if (keycode == 65307)
		return (destroy(env));
	return (0);
}

char	*sanitize_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n' || line[i] == '\r')
			line[i] = '\0';
		i++;
	}
	return (line);
}
