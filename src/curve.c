/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:34:17 by ygille            #+#    #+#             */
/*   Updated: 2024/12/11 18:51:44 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
void bresenham(t_mlx *mlx, int x1, int y1, int x2, int y2, int z);

void	draw_curve(t_mlx *mlx, t_curve curve)
{
	curve.sx = iso_x(curve.sx, curve.sy) * mlx->map->zoom;
	curve.sy = iso_y(curve.sx, curve.sy, curve.sz) * mlx->map->zoom;
	curve.ex = iso_x(curve.ex, curve.ey) * mlx->map->zoom;
	curve.ey = iso_y(curve.ex, curve.ey, curve.ez) * mlx->map->zoom;
	// ft_printf("sx = %d, sy = %d, sz = %d, ex = %d, ey = %d, ez = %d\n", curve.sx, curve.sy, curve.sz, curve.ex, curve.ey, curve.ez);
	// draw_line(mlx, curve);
	bresenham(mlx, curve.sx, curve.sy, curve.ex, curve.ey, curve.sz);
}

void	draw_line(t_mlx *mlx, t_curve curve)
{
	float	s;
	float	y;
	int		i;

	s = (float)(curve.ey - curve.sy) / (float)(curve.ex - curve.sx);
	i = curve.sx;
	while (i <= curve.ex)
	{
		y = s * (i - curve.sx) + curve.sy;
		verif_pos(mlx, i, y, curve.sz);
		i++;
	}
}

void	verif_pos(t_mlx *mlx, int x, int y, int z)
{
	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
		mlx->img_data[x + y * WIDTH] = gradient(z, mlx->map->max_altitude);
	else
		ft_printf("Bad pos x = %d, y = %d, z = %d\n", x, y, z);
}

void bresenham(t_mlx *mlx, int x1, int y1, int x2, int y2, int z)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
	{
        verif_pos(mlx, x1, y1, z);
        if (x1 == x2 && y1 == y2) 
			break;
        int e2 = 2 * err;
        if (e2 > -dy)
		{
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y1 += sy;
        }
    }
}
