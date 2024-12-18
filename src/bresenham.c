/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:28:06 by ygille            #+#    #+#             */
/*   Updated: 2024/12/18 13:51:07 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void			b_calc(int *err, int dm, int *a, int sa);
static t_bresenham	init_bresenham(t_curve curve);
static int			max(int a, int b);

/*
** Bresenham's line algorithm
*/
void	bresenham(t_mlx *mlx, t_curve curve)
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
			break ;
		b.err1 -= b.dx;
		b.err2 -= b.dy;
		b.err3 -= b.dz;
		if (b.err1 < 0)
			b_calc(&b.err1, b.dm, &x, b.sx);
		if (b.err2 < 0)
			b_calc(&b.err2, b.dm, &y, b.sy);
		if (b.err3 < 0)
			b_calc(&b.err3, b.dm, &z, b.sz);
	}
}

static void	b_calc(int *err, int dm, int *a, int sa)
{
	*err += dm;
	*a += sa;
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
	b.dm = max(b.dx, max(b.dy, b.dz));
	b.err1 = b.dm / 2;
	b.err2 = b.dm / 2;
	b.err3 = b.dm / 2;
	return (b);
}

static	int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
