/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:31:44 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 13:26:09 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Retrieve the map from the file
*/
t_map	*retrieve_map(char *map_file)
{
	t_map	*map;

	map = map_init();
	get_map_size(map, map_file);
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

/*
** Parse the map file to get the size and the max altitude
*/
void	get_map_size(t_map *map, char *map_file)
{
	int		fd;
	int		i;

	fd = open_map(map_file);
	i = calc_map_size(fd);
	if (i == 0)
		free_error(NULL, map, 0);
	map->height = i;
	close(fd);
	map->tab = malloc(sizeof(int *) * map->height);
	if (map->tab == NULL)
		free_error(NULL, map, 0);
	i = 0;
	fd = open_map(map_file);
	while (i < map->height)
	{
		parse_map_line(map, fd, i);
		i++;
	}
	return ;
}

/*
** Parse a line of the map file to get the max altitude
*/
int	max_alt(char *line, int max)
{
	while (*line != '\0')
	{
		if (*line - '0' > max && *line != ' ')
			max = *line - '0';
		printf("char = %c\n", *line);
		line++;
	}
	return (max);
}

/*
** Initialize the map structure
*/
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
