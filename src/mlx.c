/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:36:09 by ygille            #+#    #+#             */
/*   Updated: 2025/02/07 20:21:18 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Open a new window with the given title
*/
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

/*
** Set the input hooks and start the mlx loop
*/
void	input_wait(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, &key_hook, (void *)mlx);
	mlx_mouse_hook(mlx->win, &mouse_hook, (void *)mlx);
	mlx_hook(mlx->win, ON_DESTROY, KEY_RELEASE, &destroy_hook, (void *)mlx);
	mlx_loop_hook(mlx->id, &frame_calc, (void *)mlx);
	mlx_loop(mlx->id);
	return ;
}

/*
** Create a new image
*/
void	new_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->id, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		free_error(mlx, NULL, 0);
	mlx->img_data = (int *)mlx_get_data_addr
		(mlx->img, &(mlx->depth), &(mlx->size_line), &(mlx->endian));
	return ;
}

/*
** Clear the image and create a new one
*/
void	clear_img(t_mlx *mlx)
{
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->id, mlx->img);
	new_image(mlx);
}

/*
** Close the window and destroy the image
*/
void	close_window(t_mlx *mlx)
{
	if (mlx->id)
	{
		if (mlx->img)
			mlx_destroy_image(mlx->id, mlx->img);
		if (mlx->win)
			mlx_destroy_window(mlx->id, mlx->win);
		if (mlx->id)
			mlx_destroy_display(mlx->id);
	}
}
