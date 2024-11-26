/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:12:15 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 13:37:02 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_grid(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			if (j + 1 < mlx->map->width)
				draw_line(mlx, i * mlx->map->zoom, j * mlx->map->zoom, i * mlx->map->zoom, (j + 1) * mlx->map->zoom);
			if (i + 1 < mlx->map->height)
				draw_line(mlx, i * mlx->map->zoom, j * mlx->map->zoom, (i + 1) * mlx->map->zoom, j * mlx->map->zoom);
			j++;
		}
		i++;
	}
	return ;
}

void	draw_line(t_mlx *mlx, int sx, int sy, int ex, int ey)
{
	int		dx;
	int		dy;
	int		x;
	int		y;

	dx = ex - sx;
	dy = ey - sy;
	x = sx;
	y = sy;
	if (abs(dx) > abs(dy))
	{
		while (x != ex)
		{
			mlx->img_data[x + y * WIDTH] = pixel_color(0, 255, 0, 0);
			x += dx > 0 ? 1 : -1;
			y += dy * (ex - x) / dx;
		}
	}
	else
	{
		while (y != ey)
		{
			mlx->img_data[x + y * WIDTH] = pixel_color(0, 255, 0, 0);
			y += dy > 0 ? 1 : -1;
			x += dx * (ey - y) / dy;
		}
	}
	return ;
}
