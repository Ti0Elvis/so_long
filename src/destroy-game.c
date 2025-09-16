/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy-game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:53:53 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 15:26:59 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid)
{
	int	i;

	i = 0;
	if (grid)
	{
		while (grid[i])
		{
			free(grid[i]);
			i++;
		}
		free(grid);
	}
}

void	free_textures(void *mlx, t_textures textures)
{
	if (textures.wall)
		mlx_destroy_image(mlx, textures.wall);
	if (textures.exit)
		mlx_destroy_image(mlx, textures.exit);
	if (textures.floor)
		mlx_destroy_image(mlx, textures.floor);
	if (textures.player)
		mlx_destroy_image(mlx, textures.player);
	if (textures.collectible)
		mlx_destroy_image(mlx, textures.collectible);
}

int	destroy_game(t_game *game)
{
	if (game)
	{
		free_textures(game->mlx, game->textures);
		free_grid(game->map.grid);
		if (game->mlx && game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	exit(0);
	return (0);
}
