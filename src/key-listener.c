/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key-listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:05:14 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 15:38:14 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_movement(t_game *game)
{
	move_player(game, 0, -1);
}

void	down_movement(t_game *game)
{
	move_player(game, 0, 1);
}

void	left_movement(t_game *game)
{
	move_player(game, -1, 0);
}

void	right_movement(t_game *game)
{
	move_player(game, 1, 0);
}

int	key_listener(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		destroy_game(game);
	if (keycode == KEY_UP || keycode == KEY_W)
		up_movement(game);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		down_movement(game);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		left_movement(game);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		right_movement(game);
	return (0);
}
