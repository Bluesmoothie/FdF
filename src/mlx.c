/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:36:09 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 13:57:27 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*open_window(char *title)
{
	t_mlx	*mlx;

	mlx = init_struct();
	mlx->id = mlx_init();
	if (mlx->id == NULL)
		free_error(mlx, EAGAIN);
	mlx->win = mlx_new_window(mlx->id, HEIGHT, WIDTH, title);
	if (mlx->win == NULL)
		free_error(mlx, EAGAIN);
	return (mlx);
}

void	input_wait(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, &key_hook, (void *)mlx);
	mlx_hook(mlx->win, ON_DESTROY, KEY_RELEASE, &destroy_hook, (void *)mlx);
	mlx_loop_hook(mlx->id, &test_rainbow, (void *) mlx);
	mlx_loop(mlx->id);
	return ;
}

void	new_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->id, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		free_error(mlx, 0);
	mlx->img_data = (int *)mlx_get_data_addr
		(mlx->img, &(mlx->depth), &(mlx->size_line), &(mlx->endian));
	return ;
}

t_mlx	*init_struct(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		error(0);
	mlx->id = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->img_data = NULL;
	mlx->depth = DEPTH;
	mlx->size_line = WIDTH * 4;
	mlx->endian = ENDIAN;
	return (mlx);
}
