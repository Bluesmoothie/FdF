/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:09:05 by ygille            #+#    #+#             */
/*   Updated: 2025/01/07 13:45:16 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Safely free the mlx structure
*/
void	free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->id)
			free(mlx->id);
		free(mlx);
	}
}

/*
** Safely free the map structure
*/
void	free_map(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->tab)
		{
			i = 0;
			while (i < map->height)
			{
				free(map->tab[i]);
				i++;
			}
			free(map->tab);
		}
		free(map);
	}
}
