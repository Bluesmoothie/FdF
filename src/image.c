/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 02:23:54 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:52:41 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Compute one frame and display it
*/
int	frame_calc(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	img_compute(mlx);
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
	display_menu(mlx);
	return (0);
}

/*
** Compute the view curve per curve
*/
void	img_compute(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	clear_img(mlx);
	if (mlx->view.center)
		put_center(mlx);
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			if (i > 0)
				w_curve(mlx, i, j);
			if (j > 0)
				n_curve(mlx, i, j);
			j++;
		}
		i++;
	}
}
