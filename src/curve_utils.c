/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:59 by ygille            #+#    #+#             */
/*   Updated: 2024/12/13 15:54:37 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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
