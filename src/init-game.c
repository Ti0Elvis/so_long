/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:38:12 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 15:35:07 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game(char *map_path)
{
	t_game	game;

	game.mlx = mlx_init();
	game.textures = init_textures(game.mlx);
	game.map = init_map(map_path);
	game.player = init_player(game.map);
	game.window = mlx_new_window(game.mlx, game.map.width * SIZE,
			game.map.height * SIZE, "so_long");
	render_all_map(game);
	return (game);
}
