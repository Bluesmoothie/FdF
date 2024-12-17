/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:45:34 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 13:34:38 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Parse of the map file
*/
void	parse_map_line(t_map *map, int fd, int line)
{
	char	*line_str;
	char	**line_tab;
	int		i;

	i = 0;
	line_str = get_next_line(fd);
	if (line_str == NULL)
		free_error(NULL, map, 0);
	line_tab = ft_split(line_str, ' ');
	while (line_tab[i] != NULL)
		i++;
	if (map->width == 0)
		map->width = i;
	map->tab[line] = malloc(sizeof(int) * map->width);
	if (map->tab[line] == NULL)
		free_error(NULL, map, 0);
	i = 0;
	while (line_tab[i] != NULL)
	{
		map->tab[line][i] = ft_atoi(line_tab[i]) + 1;
		if (map->tab[line][i] > map->max_altitude)
			map->max_altitude = map->tab[line][i];
		free(line_tab[i++]);
	}
	return (free(line_str), free(line_tab));
}
