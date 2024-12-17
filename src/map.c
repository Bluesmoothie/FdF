/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:31:44 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:42:22 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Initialize the map structure and retrieve the map file
*/
t_map	*retrieve_map(char *map_file)
{
	t_map	*map;

	map = map_init();
	get_map(map, map_file);
	return (map);
}

/*
** Parse the map file and fill the map structure
*/
void	get_map(t_map *map, char *map_file)
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
