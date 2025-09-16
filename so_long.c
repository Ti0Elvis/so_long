/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:55:29 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 16:20:00 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	*map_path;

	if (argc != 2)
		return (print_error("The number of arguments must be 2", NULL));
	map_path = argv[1];
	if (!check_if_map_exist(map_path))
		return (print_error("The map file does not exist", NULL));
	if (!check_if_map_extension_is_valid(map_path))
		return (print_error("The map file extension is not valid", NULL));
	if (!check_if_map_is_valid(map_path))
		return (print_error("The map is not valid", NULL));
	if (!check_map_validity(map_path))
		return (print_error("The map is not playable", NULL));
	game = init_game(map_path);
	mlx_hook(game.window, 17, 0, destroy_game, &game);
	mlx_hook(game.window, 2, 1L << 0, key_listener, &game);
	mlx_loop(game.mlx);
	return (0);
}
