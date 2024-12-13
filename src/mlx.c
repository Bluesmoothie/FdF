/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:36:09 by ygille            #+#    #+#             */
/*   Updated: 2024/12/13 19:59:00 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_mlx	*open_window(char *title, t_mlx *mlx)
{
	mlx->id = mlx_init();
	if (mlx->id == NULL)
		free_error(mlx, NULL, EAGAIN);
	mlx->win = mlx_new_window(mlx->id, HEIGHT, WIDTH, title);
	if (mlx->win == NULL)
		free_error(mlx, NULL, EAGAIN);
	return (mlx);
}

void	input_wait(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, &key_hook, (void *)mlx);
	mlx_mouse_hook(mlx->win, &mouse_hook, (void *)mlx);
	mlx_hook(mlx->win, ON_DESTROY, KEY_RELEASE, &destroy_hook, (void *)mlx);
	mlx_loop_hook(mlx->id, &view_calc, (void *)mlx);
	mlx_loop(mlx->id);
	return ;
}

void	new_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->id, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		free_error(mlx, NULL, 0);
	mlx->img_data = (int *)mlx_get_data_addr
		(mlx->img, &(mlx->depth), &(mlx->size_line), &(mlx->endian));
	return ;
}

void	clear_img(t_mlx *mlx)
{
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->id, mlx->img);
	new_image(mlx);
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
	mlx->view.x_offset = OFFSET_X;
	mlx->view.y_offset = OFFSET_Y;
	mlx->view.center = 0;
	mlx->view.angle = ANGLE;
	mlx->view.zoom = 1;
	mlx->view.x_pos = 0;
	mlx->view.y_pos = 0;
	mlx->view.view_type = ISO;
	return (mlx);
}
