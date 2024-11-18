/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:23:33 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 16:08:40 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (keycode == 65307)
		quit(mlx);
	else if (keycode == 114)
		test_image((void *)mlx, pixel_color(0, 255, 0, 0));
	else if (keycode == 103)
		test_image((void *)mlx, pixel_color(0, 0, 255, 0));
	else if (keycode == 98)
		test_image((void *)mlx, pixel_color(0, 0, 0, 255));
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	(void) mlx;
	(void) button;
	(void) x;
	(void) y;
	return (0);
}

int	destroy_hook(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	quit(mlx);
	return (0);
}
