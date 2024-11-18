/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:36:09 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 12:26:15 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*open_window(char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		error(0);
	mlx->id = mlx_init();
	if (mlx->id == NULL)
		free_error((void *)mlx, EAGAIN);
	mlx->win = mlx_new_window(mlx->id, HEIGHT, WIDTH, title);
	if (mlx->win == NULL)
		free_error((void *)mlx, EAGAIN);
	return (mlx);
}

void	input_wait(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, &key_hook, (void *)mlx);
	mlx_hook(mlx->win, ON_DESTROY, KEY_RELEASE, &destroy_hook, (void *)mlx);
	mlx_loop(mlx->id);
	return ;
}
