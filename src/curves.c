/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:59 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:32:43 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Draw a curve from the current point to the next point
** using Bresenham's line algorithm
*/

void	n_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;

	curve.sx = sx;
	curve.sy = sy;
	curve.sz = mlx->map->tab[sx][sy];
	curve.ex = curve.sx;
	curve.ey = sy - 1;
	curve.ez = mlx->map->tab[sx][sy - 1];
	draw_curve(mlx, curve);
}

void	w_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;


	curve.sx = sx;
	curve.sy = sy;
	curve.sz = mlx->map->tab[sx][sy];
	curve.ex = sx - 1;
	curve.ey = curve.sy;
	curve.ez = mlx->map->tab[sx - 1][sy];
	draw_curve(mlx, curve);
}

void	e_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;

	curve.sx = sx;
	curve.sy = sy;
	curve.sz = mlx->map->tab[sx][sy];
	curve.ex = sx + 1;
	curve.ey = curve.sy;
	curve.ez = mlx->map->tab[sx + 1][sy];
	draw_curve(mlx, curve);
}

void	s_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;

	curve.sx = sx;
	curve.sy = sy;
	curve.sz = mlx->map->tab[sx][sy];
	curve.ex = curve.sx;
	curve.ey = sy + 1;
	curve.ez = mlx->map->tab[sx][sy + 1];
	draw_curve(mlx, curve);
}
