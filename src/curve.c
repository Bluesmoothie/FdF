/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:34:17 by ygille            #+#    #+#             */
/*   Updated: 2024/12/12 12:23:40 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
void	bresenham(t_mlx *mlx, t_curve curve);
#define max(a,b) ((a) > (b) ? (a) : (b))

void	draw_curve(t_mlx *mlx, t_curve curve)
{
	curve.sx = iso_x(curve.sx, curve.sy) * mlx->map->zoom;
	curve.sy = iso_y(curve.sx, curve.sy, curve.sz) * mlx->map->zoom;
	curve.ex = iso_x(curve.ex, curve.ey) * mlx->map->zoom;
	curve.ey = iso_y(curve.ex, curve.ey, curve.ez) * mlx->map->zoom;
	curve.sz *= mlx->map->zoom;
	curve.ez *= mlx->map->zoom;
	bresenham(mlx, curve);
}

void	verif_pos(t_mlx *mlx, int x, int y, int z)
{
	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
		mlx->img_data[x + y * WIDTH] = gradient(z / mlx->map->zoom, mlx->map->max_altitude);
	else
		ft_printf("Bad pos x = %d, y = %d, z = %d\n", x, y, z);
}

void bresenham(t_mlx *mlx, t_curve curve)
{
    int dx = abs(curve.ex - curve.sx);
    int dy = abs(curve.ey - curve.sy);
    int dz = abs(curve.ez - curve.sz);
    int sx = (curve.sx < curve.ex) ? 1 : -1;
    int sy = (curve.sy < curve.ey) ? 1 : -1;
    int sz = (curve.sz < curve.ez) ? 1 : -1;
    
    int dm = max(dx, max(dy, dz));
    int x = curve.sx, y = curve.sy, z = curve.sz;
    
    int err1 = dm / 2;
    int err2 = dm / 2;
    int err3 = dm / 2;

    while (1)
    {
        verif_pos(mlx, x, y, z);
        if (x == curve.ex && y == curve.ey && z == curve.ez) 
            break;

        err1 -= dx;
        err2 -= dy;
        err3 -= dz;

        if (err1 < 0)
        {
            err1 += dm;
            x += sx;
        }
        if (err2 < 0)
        {
            err2 += dm;
            y += sy;
        }
        if (err3 < 0)
        {
            err3 += dm;
            z += sz;
        }
    }
}
