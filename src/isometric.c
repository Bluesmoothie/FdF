/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:48 by ygille            #+#    #+#             */
/*   Updated: 2024/12/13 20:25:02 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Calculate the isometric x and y coordinate
*/
int	iso_x(int x, int z, t_mlx *mlx)
{
	(void)mlx;
	return ((x - z) / sqrt(2));
}

int	iso_y(int x, int y, int z, t_mlx *mlx)
{
	(void)mlx;
	return (((x + z) + (2 * y)) / sqrt(6));
}

void	calc_view(t_mlx *mlx)
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
