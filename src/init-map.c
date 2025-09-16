/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <evera@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:30:34 by evera             #+#    #+#             */
/*   Updated: 2025/09/16 15:28:37 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_lines(char *map_path)
{
	int		fd;
	char	*line;
	size_t	line_count;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

char	**load_map(char *map_path, int height)
{
	int		i;
	int		fd;
	char	*line;
	char	**grid;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	grid = ft_calloc(height + 1, sizeof(char *));
	if (!grid)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		grid[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	grid[i] = NULL;
	close(fd);
	return (grid);
}

size_t	get_map_max_width(char **grid)
{
	size_t	i;
	size_t	width;

	i = 0;
	width = 0;
	while (grid[i])
	{
		if (ft_strlen(grid[i]) > width)
			width = ft_strlen(grid[i]);
		i++;
	}
	return (width);
}

int	calculate_collectibles(char **grid)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_map	init_map(char *map_path)
{
	t_map	map;

	map.width = 0;
	map.height = 0;
	map.grid = NULL;
	map.collectibles = 0;
	map.exit_reachable = 0;
	map.height = count_lines(map_path);
	if (map.height <= 1)
		print_error("Error to count lines of the map", NULL);
	map.grid = load_map(map_path, map.height);
	if (!map.grid)
		print_error("Error to load the map", NULL);
	map.width = get_map_max_width(map.grid);
	if (map.width <= 1)
		print_error("Error to get the max width of the map", NULL);
	map.collectibles = calculate_collectibles(map.grid);
	if (map.collectibles == 0)
		print_error("No collectibles found on the map", NULL);
	return (map);
}
