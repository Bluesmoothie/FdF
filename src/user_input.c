/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:23:33 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 11:03:53 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	ft_printf("KEY_HOOK\nkeycode = %i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->id, mlx->win);
		quit();
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	(void) mlx;
	ft_printf("MOUSE_HOOK\nbutton = %i\n     x = %i\n     y = %i\n", button, x, y);
	return (0);
}
