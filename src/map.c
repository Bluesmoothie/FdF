/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:31:44 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 19:03:08 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*retrieve_map(char *map_file)
{
	t_map	*map;

	map = map_init();
	get_map_size(map, map_file);
	ft_printf("Map height = %u\nMap  width = %u\nMax    alt = %u\n", map->height, map->width, map->max_altitude);
	return (map);
}

int	open_map(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error(0);
	return (fd);
}

void	get_map_size(t_map *map, char *map_file)
{
	char	*line;
	int		fd;

	fd = open_map(map_file);
	line = get_next_line(fd);
	if (line == NULL)
		free_error(NULL, map, 0);
	map->width = ft_strlen(line);
	while (line != NULL)
	{
		if (ft_strlen(line) != map->width)
			free_error(NULL, map, -2);
		(map->height)++;
		map->max_altitude = max_alt(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}

unsigned int	max_alt(char *line)
{
	unsigned int	max;

	max = 0;
	while (*line != '\0')
	{
		if ((unsigned int)(*line - '0') > max)
			max = *line - '0';
		line++;
	}
	return (max);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		error(0);
	map->height = 0;
	map->width = 0;
	map->max_altitude = 0;
	return (map);
}
