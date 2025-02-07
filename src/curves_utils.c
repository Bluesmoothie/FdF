/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curves_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:34:17 by ygille            #+#    #+#             */
/*   Updated: 2025/02/07 20:20:45 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Modify the curve coordinates according to the view parameters
** and display it
*/
void	draw_curve(t_mlx *mlx, t_curve curve)
{
	apply_zoom(mlx, &curve);
	apply_view(mlx, &curve);
	center(mlx);
	bresenham(mlx, curve);
}

/*
** Verify if the position is in the window and display the pixel
*/
void	verif_pos(t_mlx *mlx, int x, int y, int z)
{
	x += mlx->view.x_offset + mlx->view.x_pos;
	y += mlx->view.y_offset + mlx->view.y_pos;
	apply_angle(&x, &y, mlx->view.angle);
	if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
		mlx->img_data[x + y * WIDTH]
			= gradient(z / mlx->view.zoom, mlx->map->max_altitude);
}

/*
** Apply the view type to the curve
*/
void	apply_view(t_mlx *mlx, t_curve *curve)
{
	if (mlx->view.view_type == ISO)
	{
		curve->sx = iso_x(curve->sx, curve->sz);
		curve->sy = iso_y(curve->sx, curve->sy, curve->sz);
		curve->ex = iso_x(curve->ex, curve->ez);
		curve->ey = iso_y(curve->ex, curve->ey, curve->ez);
	}
	else if (mlx->view.view_type == AXO)
	{
		curve->sx = axo_x(curve->sx, curve->sz);
		curve->sy = axo_y(curve->sx, curve->sy, curve->sz);
		curve->ex = axo_x(curve->ex, curve->ez);
		curve->ey = axo_y(curve->ex, curve->ey, curve->ez);
	}
	else if (mlx->view.view_type == DD)
		return ;
}

/*
** Center the map view in the window
*/
void	center(t_mlx *mlx)
{
	mlx->view.x_offset = (HEIGHT - mlx->map->height * mlx->view.zoom) / 2;
	mlx->view.y_offset = (WIDTH - mlx->map->width * mlx->view.zoom) / 2;
}

/*
** Apply zoom level to the curve
*/
void	apply_zoom(t_mlx *mlx, t_curve *curve)
{
	curve->sx *= mlx->view.zoom;
	curve->sy *= mlx->view.zoom;
	curve->sz *= mlx->view.zoom;
	curve->ex *= mlx->view.zoom;
	curve->ey *= mlx->view.zoom;
	curve->ez *= mlx->view.zoom;
}
