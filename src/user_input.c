/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:23:33 by ygille            #+#    #+#             */
/*   Updated: 2024/12/12 16:42:53 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Handle the key events
*/
int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (keycode == ESC)
		quit(mlx);
	else if (move_code(keycode))
		move_view(mlx, keycode);
	else if (keycode == KEY_X)
		display_center(mlx);
	else if (keycode == KEY_E || keycode == KEY_Q)
		turn_view(mlx, keycode);
	return (0);
}

int	move_code(int keycode)
{
	return (keycode == A_LEFT || keycode == A_RIGHT || keycode == A_UP
		|| keycode == A_DOWN || keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D);
}

/*
** Handle the mouse events
*/
int	mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	(void) x;
	(void) y;
	if (button == SCROLL_DOWN || button == SCROLL_UP)
		zoom_view(mlx, button);
	return (0);
}

/*
** Handle the destroy event
** when the cross is clicked
*/
int	destroy_hook(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	quit(mlx);
	return (0);
}
