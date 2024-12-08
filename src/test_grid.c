/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:12:15 by ygille            #+#    #+#             */
/*   Updated: 2024/12/09 16:37:48 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Draw a grid adapted for the map on the window
*/
void	draw_grid(t_mlx *mlx)
{
    int	i;
    int	j;
    int	color;

    i = 0;
    while (i < mlx->map->height)
    {
        j = 0;
        while (j < mlx->map->width)
        {
            color = gradient(mlx->map->tab[i][j], mlx->map->max_altitude);
            if (j < mlx->map->width - 1)
                draw_line(mlx, i * mlx->map->zoom, j * mlx->map->zoom, i * mlx->map->zoom, (j + 1) * mlx->map->zoom, color);
            if (i < mlx->map->height - 1)
                draw_line(mlx, i * mlx->map->zoom, j * mlx->map->zoom, (i + 1) * mlx->map->zoom, j * mlx->map->zoom, color);
            j++;
        }
        i++;
    }
}

/*
** Draw a line between two points on the window
*/
void	draw_line(t_mlx *mlx, int sy, int sx, int ey, int ex, int color)
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
			mlx->img_data[x + y * WIDTH] = color;
			x += dx > 0 ? 1 : -1;
			y += dy * (ex - x) / dx;
		}
	}
	else
	{
		while (y != ey)
		{
			mlx->img_data[x + y * WIDTH] = color;
			y += dy > 0 ? 1 : -1;
			x += dx * (ey - y) / dy;
		}
	}
	return ;
}

/*
** Draw a semi 3d grid adapted for the map on the window
*/
void	td_grid(t_mlx *mlx)
{
	int	i;
    int	j;
    int	color;

    i = 0;
    while (i < mlx->map->height)
    {
        j = 0;
        while (j < mlx->map->width)
        {
            color = gradient(mlx->map->tab[i][j], mlx->map->max_altitude);
            if (j < mlx->map->width - 1)
                draw_line(mlx, iso_x(i, j) * mlx->map->zoom, iso_y(i, j, mlx->map->tab[i][j]) * mlx->map->zoom, iso_x(i, j) * mlx->map->zoom, (iso_y(i, j, mlx->map->tab[i][j]) + 1) * mlx->map->zoom, color);
            if (i < mlx->map->height - 1)
                draw_line(mlx, iso_x(i, j) * mlx->map->zoom, iso_y(i, j, mlx->map->tab[i][j]) * mlx->map->zoom, (iso_x(i, j) + 1) * mlx->map->zoom, iso_y(i, j, mlx->map->tab[i][j]) * mlx->map->zoom, color);
            j++;
        }
        i++;
    }
}
