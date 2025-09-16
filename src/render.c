/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:34:35 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 15:35:01 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game game, int x, int y)
{
	char	tile;

	tile = game.map.grid[y][x];
	if (tile == '1')
		mlx_put_image_to_window(game.mlx, game.window, game.textures.wall, x
			* SIZE, y * SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game.mlx, game.window, game.textures.floor, x
			* SIZE, y * SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game.mlx, game.window,
			game.textures.collectible, x * SIZE, y * SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game.mlx, game.window, game.textures.exit, x
			* SIZE, y * SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game.mlx, game.window, game.textures.player, x
			* SIZE, y * SIZE);
}

void	render_all_map(t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game.map.height)
	{
		x = 0;
		while (x < game.map.width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
