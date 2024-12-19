/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:33:27 by ygille            #+#    #+#             */
/*   Updated: 2024/12/19 14:43:47 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Apply settings to the view structure
*/

void	move_view(t_mlx *mlx, int keycode)
{
	if (keycode == A_RIGHT || keycode == KEY_D)
		mlx->view.y_pos -= 100;
	else if (keycode == A_LEFT || keycode == KEY_A)
		mlx->view.y_pos += 100;
	else if (keycode == A_DOWN || keycode == KEY_S)
		mlx->view.x_pos -= 100;
	else if (keycode == A_UP || keycode == KEY_W)
		mlx->view.x_pos += 100;
}

void	turn_view(t_mlx *mlx, int keycode)
{
	if (keycode == KEY_E)
		mlx->view.angle += 1;
	else if (keycode == KEY_Q)
		mlx->view.angle -= 1;
	if (mlx->view.angle < 1)
		mlx->view.angle = 4;
	if (mlx->view.angle > 4)
		mlx->view.angle = 1;
}

void	zoom_view(t_mlx *mlx, int button)
{
	if (button == SCROLL_UP)
		mlx->view.zoom *= 2;
	else if (button == SCROLL_DOWN)
		mlx->view.zoom /= 2;
	if (mlx->view.zoom < 1)
		mlx->view.zoom = 1;
	if (mlx->view.zoom > 256)
		mlx->view.zoom = 256;
}

void	display_center(t_mlx *mlx)
{
	if (mlx->view.center == 0)
		mlx->view.center = 1;
	else
		mlx->view.center = 0;
}
