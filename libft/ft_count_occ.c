/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:39:03 by labdello          #+#    #+#             */
/*   Updated: 2024/07/26 15:51:33 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_occ(char **tab, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
