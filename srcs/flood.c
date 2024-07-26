/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:07:48 by labdello          #+#    #+#             */
/*   Updated: 2024/07/30 17:03:10 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_exit(char **map, int *is_exited, size_t x, size_t y)
{
	if (x < 0 || y < 0 || x >= ft_strlen(map[0]) || y >= ft_tablen(map))
		return ;
	if (map[y][x] == 'F' || map[y][x] == wall)
		return ;
	if (map[y][x] == end)
		*is_exited = 1;
	map[y][x] = 'F';
	flood_exit(map, is_exited, x, y - 1);
	flood_exit(map, is_exited, x, y + 1);
	flood_exit(map, is_exited, x - 1, y);
	flood_exit(map, is_exited, x + 1, y);
}

int	is_walled(char **map)
{
	size_t	i;
	size_t	j;
	size_t	max_x;
	size_t	max_y;

	i = 0;
	max_x = ft_strlen(map[0]) - 1;
	max_y = ft_tablen(map) - 1;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((i == 0 || j == 0) && map[i][j] != wall)
				return (0);
			else if ((i == max_y || j == max_x) && map[i][j] != wall)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood(t_env *env)
{
	int		is_exited;
	char	**map_copy;

	is_exited = 0;
	map_copy = env->map;
	if (!is_walled(map_copy))
		return_error("Map is not correctly walled\n", 1, env);
	flood_exit(map_copy, &is_exited, env->start_pos->x, env->start_pos->y);
	if (!is_exited)
		return_error("Map cannot be exited\n", 1, env);
	printf("env->map[1][1] = %c\n", env->map[1][1]);
}
