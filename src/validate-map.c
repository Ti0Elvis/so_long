/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:00:39 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 16:35:54 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_rectangular(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		if ((int)ft_strlen(map.grid[i]) != map.width)
			return (0);
		i++;
	}
	j = 0;
	while (j < map.width)
	{
		if (map.grid[0][j] != '1' || map.grid[map.height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < map.height)
	{
		if (map.grid[i][0] != '1' || map.grid[i][map.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_content_valid(char **grid)
{
	int	i;
	int	j;
	int	player_count;

	if (!grid)
		return (0);
	i = 0;
	player_count = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (!is_valid_char(grid[i][j]))
				return (0);
			if (grid[i][j] == 'P')
				player_count++;
			if (player_count > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
