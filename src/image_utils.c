/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:03:48 by ygille            #+#    #+#             */
/*   Updated: 2024/12/12 16:51:53 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_center(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < HEIGHT - 1)
	{
		mlx->img_data[i + (WIDTH / 2) * WIDTH] = pixel_color(0, 255, 255, 255);
		i++;
	}
	i = 0;
	while (i < WIDTH - 1)
	{
		mlx->img_data[(HEIGHT / 2) + i * WIDTH] = pixel_color(0, 255, 255, 255);
		i++;
	}
}

void	move_view(t_mlx *mlx, int keycode)
{
	if (keycode == A_LEFT || keycode == KEY_A)
	{
		mlx->view.x_offset -= 10;
		mlx->view.y_offset += 9;
	}
	else if (keycode == A_RIGHT || keycode == KEY_D)
	{
		mlx->view.x_offset += 10;
		mlx->view.y_offset -= 9;
	}
	else if (keycode == A_UP || keycode == KEY_W)
		mlx->view.y_offset -= 10;
	else if (keycode == A_DOWN || keycode == KEY_S)
		mlx->view.y_offset += 10;
}

void	turn_view(t_mlx *mlx, int keycode)
{
	if (keycode == KEY_E)
		mlx->view.angle += 1;
	else if (keycode == KEY_Q)
		mlx->view.angle -= 1;
}

void	zoom_view(t_mlx *mlx, int button)
{
	if (button == SCROLL_UP)
		mlx->view.zoom += 1;
	else if (button == SCROLL_DOWN)
		mlx->view.zoom -= 1;
	if (mlx->view.zoom < 1)
		mlx->view.zoom = 1;
}

void	display_center(t_mlx *mlx)
{
	if (mlx->view.center == 0)
		mlx->view.center = 1;
	else
		mlx->view.center = 0;
}
