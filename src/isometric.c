/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:48 by ygille            #+#    #+#             */
/*   Updated: 2024/12/13 18:49:37 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Calculate the isometric x and y coordinate
*/
int	iso_x(int x, int y, t_mlx *mlx)
{
	return ((int)((x - y) * cos(mlx->view.angle)));
}

int	iso_y(int x, int y, int z, t_mlx *mlx)
{
	return ((int)((x + y) * sin(mlx->view.angle) - z));
}

void	iso_view(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	clear_img(mlx);
	if (mlx->view.center)
		put_center(mlx);
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			if (i > 0)
				w_curve(mlx, i, j);
			if (j > 0)
				n_curve(mlx, i, j);
			j++;
		}
		i++;
	}
}
