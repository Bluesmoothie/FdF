/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:05:15 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 14:54:01 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	pixel_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	test_rainbow(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) param;
	if (mlx->img == NULL)
		new_image(mlx);
	fill_color(mlx, pixel_color(0, 255, 255, 0));
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 10);
	return (0);
}

void	fill_color(t_mlx *mlx, int color)
{
	int	i;
	int	j;
	int	*pixel;

	i = 0;
	j = 0;
	pixel = mlx->img_data;
	ft_printf("img_data = %p\ncolor = %d\n", mlx->img_data, color);
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			*pixel = color;
			pixel++;
			j++;
		}
		i++;
	}
	return ;
}
