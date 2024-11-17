/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:36:09 by ygille            #+#    #+#             */
/*   Updated: 2024/11/17 19:36:19 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*open_window(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		error(0);
	mlx->id = mlx_init();
	if (mlx->id == NULL)
		free_error((void *)mlx, EAGAIN);
	mlx->win = mlx_new_window(mlx->id, 512, 512, "FdF");
	if (mlx->win == NULL)
		free_error((void *)mlx, EAGAIN);
	return (mlx);
}
