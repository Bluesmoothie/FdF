/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:48 by ygille            #+#    #+#             */
/*   Updated: 2024/12/11 17:23:29 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Calculate the isometric x and y coordinate
*/
int	iso_x(int x, int y)
{
	return (abs((int)(((x - y) * cos(ANGLE)) + OFFSET_X)));
}

int	iso_y(int x, int y, int z)
{
	return (abs((int)(((x + y) * sin(ANGLE) - z) + OFFSET_Y)));
}

void	iso_view(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			if (i > 1)
				w_curve(mlx, i, j);
			if (j > 1)
				n_curve(mlx, i, j);
			if (j < mlx->map->width - 1)
				s_curve(mlx, i, j);
			if (i < mlx->map->height - 1)
				e_curve(mlx, i, j);
			j++;
		}
		i++;
	}
}
