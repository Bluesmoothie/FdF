/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:28:06 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 18:48:52 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_bresenham	init_bresenham(t_curve curve);
static int			max(int a, int b);

/*
** Bresenham's line algorithm
*/
void bresenham(t_mlx *mlx, t_curve curve)
{
	t_bresenham	b;
	int			x;
	int			y;
	int			z;

	b = init_bresenham(curve);
	x = curve.sx;
	y = curve.sy;
	z = curve.sz;
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

static t_bresenham	init_bresenham(t_curve curve)
{
	t_bresenham	b;

	b.dx = abs(curve.ex - curve.sx);
	b.dy = abs(curve.ey - curve.sy);
	b.dz = abs(curve.ez - curve.sz);
	if (curve.sx < curve.ex)
		b.sx = 1;
	else
		b.sx = -1;
	if (curve.sy < curve.ey)
		b.sy = 1;
	else
		b.sy = -1;
	if (curve.sz < curve.ez)
		b.sz = 1;
	else
		b.sz = -1;
	b.dm = max(dx, max(dy, dz));
	b.err1 = dm / 2;
	b.err2 = dm / 2;
	b.err3 = dm / 2;
	return (b);
}

static	int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
