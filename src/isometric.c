/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:48 by ygille            #+#    #+#             */
/*   Updated: 2024/12/12 17:05:45 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Calculate the isometric x and y coordinate
*/
int	iso_x(int x, int y, t_mlx *mlx)
{
	return ((int)(((x - y) * cos(mlx->view.angle)) + mlx->view.x_offset));
}

int	iso_y(int x, int y, int z, t_mlx *mlx)
{
	return ((int)(((x + y) * sin(mlx->view.angle) - z) + mlx->view.y_offset));
}

void	iso_view(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	clear_img(mlx);
	if (mlx->view.center)
		put_center(mlx);
	while (x < mlx->map->height)
	{
		y = 0;
		while (y < mlx->map->width)
		{
			if (x > 1)
				w_curve(mlx, x, y);
			if (y > 1)
				n_curve(mlx, x, y);
			if (x < mlx->map->width - 1)
				e_curve(mlx, x, y);
			if (y < mlx->map->height - 1)
				s_curve(mlx, x, y);
			y++;
		}
		x++;
	}
}
