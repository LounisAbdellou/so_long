/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:41:56 by labdello          #+#    #+#             */
/*   Updated: 2024/07/30 16:32:42 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(char *error_message, int exit_status, t_env *env)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	if (env != NULL)
		destroy(env);
	exit(exit_status);
}

void	check_file_extension(char *filename, t_env *env)
{
	char	**tab;

	tab = ft_split(filename, '.');
	if (tab == NULL)
		return_error("Something went wrong with the filename\n", 1, env);
	if (ft_strcmp(tab[ft_tablen(tab) - 1], "ber") != 0)
	{
		ft_free_tab(tab);
		return_error("Wrong file extension, only .ber are accepted\n", 1, env);
	}
	ft_free_tab(tab);
}

void	check_file(char *filepath, t_env *env)
{
	int		fd;
	char	**tab;
	char	buffer[5];

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return_error("File does not exist\n", 1, env);
	if (read(fd, buffer, 5) < 1)
		return_error("File is empty\n", 1, env);
	tab = ft_split(filepath, '/');
	if (tab == NULL)
		return_error("Something went wrong with the filepath\n", 1, env);
	check_file_extension(tab[ft_tablen(tab) - 1], env);
	ft_free_tab(tab);
	close(fd);
}

int	has_extra_param(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != start && str[i] != end
			&& str[i] != item && str[i] != wall && str[i] != floor)
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_env *env)
{
	size_t	i;

	i = 1;
	while (env->map[i] != NULL)
	{
		if (has_extra_param(env->map[i]))
			return_error("Map has unknown parameters\n", 1, env);
		if (ft_strlen(env->map[i]) != ft_strlen(env->map[i - 1]))
			return_error("Map shape should be rectangular\n", 1, env);
		i++;
	}
	if (ft_countt_occ(env->map, item) < 1)
		return_error("Map should have at least one collectible item\n", 1, env);
	else if (ft_countt_occ(env->map, start) != 1)
		return_error("Map should have exactly one starting position\n", 1, env);
	else if (ft_countt_occ(env->map, end) != 1)
		return_error("Map should have exactly one exit\n", 1, env);
	flood(env);
}
