/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:27:26 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 16:20:01 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_map_exist(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_if_map_extension_is_valid(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len < 5 || ft_strncmp(&map_path[len - 4], ".ber", 4) != 0)
		return (0);
	return (1);
}

int	check_if_map_is_valid(char *map_path)
{
	t_map	map;

	map = init_map(map_path);
	if (!is_map_rectangular(map) || !is_map_content_valid(map.grid))
	{
		free_grid(map.grid);
		return (0);
	}
	free_grid(map.grid);
	return (1);
}

int	check_map_validity(char *map_path)
{
	t_map		map;
	t_player	player;

	map = init_map(map_path);
	player = init_player(map);
	flood_fill(&map, player.position.x, player.position.y);
	if (map.collectibles == 0 && map.exit_reachable == 1)
	{
		free_grid(map.grid);
		return (1);
	}
	free_grid(map.grid);
	return (0);
}
