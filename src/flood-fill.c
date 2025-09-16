/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood-fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:38:06 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 16:19:54 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'F')
		return ;
	if (map->grid[y][x] == 'C')
		map->collectibles--;
	if (map->grid[y][x] == 'E')
		map->exit_reachable += 1;
	map->grid[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
