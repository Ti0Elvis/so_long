/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:38:24 by evera             #+#    #+#             */
/*   Updated: 2025/09/14 12:57:20 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	init_textures(void *mlx)
{
	t_textures	textures;
	int			width;
	int			height;

	textures.wall = mlx_xpm_file_to_image(mlx, WALL, &width, &height);
	textures.exit = mlx_xpm_file_to_image(mlx, EXIT, &width, &height);
	textures.floor = mlx_xpm_file_to_image(mlx, FLOOR, &width, &height);
	textures.player = mlx_xpm_file_to_image(mlx, PLAYER, &width, &height);
	textures.collectible = mlx_xpm_file_to_image(mlx, COLLECTIBLE, &width,
			&height);
	if (!textures.wall || !textures.exit || !textures.floor || !textures.player
		|| !textures.collectible)
	{
		free_textures(mlx, textures);
		print_error("One or more textures are missing", NULL);
	}
	return (textures);
}
