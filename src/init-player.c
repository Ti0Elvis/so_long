/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:38:19 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 15:28:15 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	calculate_player_position(t_map map)
{
	int			y;
	int			x;
	t_position	position;

	y = 0;
	x = 0;
	position.x = 0;
	position.y = 0;
	while (map.grid[y] && y <= map.height)
	{
		while (map.grid[y][x] && x <= map.width)
		{
			if (map.grid[y][x] == 'P')
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (position);
}

t_player	init_player(t_map map)
{
	t_player	player;
	t_position	position;

	player.position.x = 0;
	player.position.y = 0;
	position = calculate_player_position(map);
	player.moves = 1;
	player.position.x = position.x;
	player.position.y = position.y;
	if (player.position.x == 0 && player.position.y == 0)
	{
		free_grid(map.grid);
		print_error("No player found on the map", NULL);
	}
	return (player);
}
