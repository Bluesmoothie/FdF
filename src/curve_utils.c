/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:59 by ygille            #+#    #+#             */
/*   Updated: 2024/12/11 16:29:38 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	n_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;

	curve.sx = sx * mlx->map->zoom;
	curve.sy = sy * mlx->map->zoom;
	curve.sz = mlx->map->tab[sx][sy] * mlx->map->zoom;
	curve.ex = curve.sx;
	curve.ey = sy - mlx->map->zoom;
	curve.ez = mlx->map->tab[sx][sy - 1] * mlx->map->zoom;
	draw_curve(mlx, curve);
}
void	w_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;

	curve.sx = sx * mlx->map->zoom;
	curve.sy = sy * mlx->map->zoom;
	curve.sz = mlx->map->tab[sx][sy] * mlx->map->zoom;
	curve.ex = sx - mlx->map->zoom;
	curve.ey = curve.sy;
	curve.ez = mlx->map->tab[sx - 1][sy] * mlx->map->zoom;
	draw_curve(mlx, curve);
}
void	e_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;

	curve.sx = sx * mlx->map->zoom;
	curve.sy = sy * mlx->map->zoom;
	curve.sz = mlx->map->tab[sx][sy] * mlx->map->zoom;
	curve.ex = sx + mlx->map->zoom;
	curve.ey = curve.sy;
	curve.ez = mlx->map->tab[sx + 1][sy] * mlx->map->zoom;
	draw_curve(mlx, curve);
}
void	s_curve(t_mlx *mlx, int sx, int sy)
{
	t_curve	curve;

	curve.sx = sx * mlx->map->zoom;
	curve.sy = sy * mlx->map->zoom;
	curve.sz = mlx->map->tab[sx][sy] * mlx->map->zoom;
	curve.ex = curve.sx;
	curve.ey = sy + mlx->map->zoom;
	curve.ez = mlx->map->tab[sx][sy + 1] * mlx->map->zoom;
	draw_curve(mlx, curve);
}
