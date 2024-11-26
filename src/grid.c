/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:12:15 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 14:46:22 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	draw_line(t_mlx *mlx, int sy, int sx, int ey, int ex, int color)
{
    int dx, dy, p, x, y;
    dx = ex - sx;
    dy = ey - sy;
    x = sx;
    y = sy;
    p = 2 * dy - dx;
    while (x <= ex)
    {
        if (p >= 0)
        {
            mlx->img_data[y * WIDTH + x] = color;
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            mlx->img_data[y * WIDTH + x] = color;
            p = p + 2 * dy;
        }
        x++;
    }
}
