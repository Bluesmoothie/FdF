/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:23:33 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 12:14:46 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (keycode == 65307)
		quit(mlx);
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
