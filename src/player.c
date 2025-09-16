/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:37:27 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 15:38:12 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	ft_printf("Congratulations! You've won the game in %d moves!\n",
		game->player.moves);
	destroy_game(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.position.x + dx;
	new_y = game->player.position.y + dy;
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if (game->map.grid[new_y][new_x] == '0'
		|| game->map.grid[new_y][new_x] == 'C')
	{
		if (game->map.grid[new_y][new_x] == 'C')
			game->map.collectibles--;
		game->map.grid[game->player.position.y][game->player.position.x] = '0';
		game->player.position.x = new_x;
		game->player.position.y = new_y;
		game->map.grid[game->player.position.y][game->player.position.x] = 'P';
		ft_printf("Moves: %d\n", game->player.moves++);
	}
	if (game->map.collectibles == 0 && game->map.grid[new_y][new_x] == 'E')
		end_game(game);
	render_all_map(*game);
}
