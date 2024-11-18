/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:31:44 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 13:57:42 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*retrieve_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = open_map(map_file);
	map = parse_map(fd);
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

t_map	*parse_map(int fd)
{
	t_map	*map;

	map = (t_map *) 0;
	(void) fd;
	return (map);
}
