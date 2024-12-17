/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:28:06 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:59:16 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static	int	max(int a, int b);

/*
** Bresenham's line algorithm
*/
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

static	int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
