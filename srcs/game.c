/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:24:18 by labdello          #+#    #+#             */
/*   Updated: 2024/08/05 16:22:37 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	env->is_open = 1;
	while (env->map[i] != NULL)
	{
		j = 0;
		while (env->map[i][j] != '\0')
		{
			if (env->map[i][j] == end)
				put_image(env, 'O', j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	handle_special_square(t_env *env, t_point next_pos)
{
	int	i;
	int	j;
	int	has_item;

	i = 0;
	has_item = 0;
	if (env->map[next_pos.y][next_pos.x] == item)
		env->map[next_pos.y][next_pos.x] = floor;
	else if (env->map[next_pos.y][next_pos.x] == end && env->is_open)
		destroy(env);
	while (env->map[i] != NULL)
	{
		j = 0;
		while (env->map[i][j] != '\0')
		{
			if (env->map[i][j] == item)
				has_item = 1;
			j++;
		}
		i++;
	}
	if (!has_item)
		open_exit(env);
}

int	execute_move(t_env *env, t_point curr_pos, t_point next_pos, char direction)
{
	int		next_valid;
	char	square;

	square = env->map[next_pos.y][next_pos.x];
	next_valid = (square == floor || square == start || square == item);
	if (square == wall)
		return (0);
	else if (env->map[curr_pos.y][curr_pos.x] == end && next_valid)
	{
		put_image(env, direction, next_pos.x * 32, next_pos.y * 32);
		put_image(env, end, curr_pos.x * 32, curr_pos.y * 32);
	}
	else if (next_valid || (square == end && !env->is_open))
	{
		put_image(env, direction, next_pos.x * 32, next_pos.y * 32);
		put_image(env, floor, curr_pos.x * 32, curr_pos.y * 32);
	}
	handle_special_square(env, next_pos);
	return (1);
}

int	move_character(t_env *env, char direction)
{
	static unsigned int	count;
	t_point				next_pos;

	if (count < 1)
		count = 0;
	next_pos.x = env->current_pos.x;
	next_pos.y = env->current_pos.y;
	if (direction == 'U')
		next_pos.y -= 1;
	else if (direction == 'D')
		next_pos.y += 1;
	else if (direction == 'L')
		next_pos.x -= 1;
	else if (direction == 'R')
		next_pos.x += 1;
	if (execute_move(env, env->current_pos, next_pos, direction))
	{
		count += 1;
		ft_printf("Move count: %u\n", count);
		env->current_pos.x = next_pos.x;
		env->current_pos.y = next_pos.y;
		return (1);
	}
	return (0);
}
