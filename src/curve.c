/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:34:17 by ygille            #+#    #+#             */
/*   Updated: 2024/12/11 17:44:34 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_curve(t_mlx *mlx, t_curve curve)
{
	int	x;
	int	y;
	int	z;
	int	k;

	x = curve.sx;
	y = curve.sy;
	z = curve.sz;
	k = 1;
	while (k <= mlx->map->zoom)
	{
		verif_pos(mlx, x, y, z);
		x = curve.sx + (k  * (curve.ex - curve.sx) / mlx->map->zoom);
		y = curve.sy + (k  * (curve.ey - curve.sy) / mlx->map->zoom);
		z = curve.sz + (k  * (curve.ez - curve.sz) / mlx->map->zoom);
		k++;
	}
}


void	verif_pos(t_mlx *mlx, int x, int y, int z)
{
	int	rx;
	int	ry;

	rx = iso_x(x, y);
	ry = iso_y(x, y, z);
	if (rx >= 0 && rx < HEIGHT && ry >= 0 && ry < WIDTH)
		mlx->img_data[rx + ry * WIDTH] = gradient(z, mlx->map->max_altitude);
	else
		ft_printf("Bad pos x = %d, y = %d, z = %d\n", rx, ry, z);
}
