/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:25:09 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:44:03 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Open the map file
*/
int	open_map(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error(MAP);
	return (fd);
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

/*
** Calculate the number of lines in the map file
*/
int	calc_map_size(int fd)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = get_next_line(fd);
	while (ptr != NULL)
	{
		free(ptr);
		ptr = get_next_line(fd);
		i++;
	}
	return (i);
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
		line++;
	}
	return (max);
}
