/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:26:03 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 16:35:29 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes
# include "./libft/libft.h"
# include "./mlx/mlx.h"

// texture size
# define SIZE 64

// key codes
# define KEY_UP 65362
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100

// texture paths
# define WALL "./src/textures/wall.xpm"
# define EXIT "./src/textures/exit.xpm"
# define FLOOR "./src/textures/floor.xpm"
# define PLAYER "./src/textures/player.xpm"
# define COLLECTIBLE "./src/textures/collectible.xpm"

// structs
typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_player
{
	int			moves;
	t_position	position;
}				t_player;

typedef struct s_map
{
	int			width;
	int			height;
	char		**grid;
	int			collectibles;
	int			exit_reachable;
}				t_map;

typedef struct s_textures
{
	void		*wall;
	void		*exit;
	void		*floor;
	void		*player;
	void		*collectible;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_player	player;
	t_textures	textures;
}				t_game;

// check-map.c
int				check_if_map_exist(char *map_path);
int				check_map_validity(char *map_path);
int				check_if_map_is_valid(char *map_path);
int				check_if_map_extension_is_valid(char *map_path);

// destroy-game.c
void			free_grid(char **grid);
int				destroy_game(t_game *game);
void			free_textures(void *mlx, t_textures textures);

// flood-fill.c
void			flood_fill(t_map *map, int x, int y);

// init-game.c
t_game			init_game(char *map_path);

// init-player.c
t_player		init_player(t_map map);

// init-textures.c
t_textures		init_textures(void *mlx);

// init-map.c
t_map			init_map(char *map_path);
size_t			count_lines(char *map_path);
size_t			get_map_max_width(char **grid);
int				calculate_collectibles(char **grid);
char			**load_map(char *map_path, int height);

// validate-map.c
int				is_map_rectangular(t_map map);
int				is_map_content_valid(char **grid);

// key-listener.c
void			up_movement(t_game *game);
void			down_movement(t_game *game);
void			left_movement(t_game *game);
void			right_movement(t_game *game);
int				key_listener(int keycode, void *param);

// player.c
void			end_game(t_game *game);
void			move_player(t_game *game, int dx, int dy);

// render.c
void			render_all_map(t_game game);
void			render_tile(t_game game, int x, int y);

// utils.c
int				is_valid_char(char c);
int				print_error(char *message, t_game *game);

#endif
