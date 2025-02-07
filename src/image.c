/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 02:23:54 by ygille            #+#    #+#             */
/*   Updated: 2025/02/07 20:20:57 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Compute one frame and display it
*/
int	frame_calc(void *param)
{
	t_mlx				*mlx;
	static t_view_param	old_view = {0};

	mlx = (t_mlx *) param;
	if (view_changed(mlx->view, old_view))
	{
		img_compute(mlx);
		mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
		display_menu(mlx);
		old_view = mlx->view;
	}
	return (0);
}

/*
** Check if the view parameters have changed
*/
int	view_changed(t_view_param view, t_view_param old_view)
{
	return (view.zoom != old_view.zoom || view.x_offset != old_view.x_offset
		|| view.y_offset != old_view.y_offset || view.center != old_view.center
		|| view.angle != old_view.angle || view.x_pos != old_view.x_pos
		|| view.y_pos != old_view.y_pos
		|| view.view_type != old_view.view_type);
}

/*
** Compute the view curve per curve
*/
void	img_compute(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	clear_img(mlx);
	if (mlx->view.center)
		put_center(mlx);
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			if (i > 0)
				w_curve(mlx, i, j);
			if (j > 0)
				n_curve(mlx, i, j);
			j++;
		}
		i++;
	}
}
