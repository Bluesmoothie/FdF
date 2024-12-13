/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axonometric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:51:19 by ygille            #+#    #+#             */
/*   Updated: 2024/12/13 19:52:36 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	axo_x(int x, int z, t_mlx *mlx)
{
	(void)mlx;
	return ((x - z) / sqrt(2));
}

int	axo_y(int x, int y, int z, t_mlx *mlx)
{
	(void)mlx;
	return (x + y + z / sqrt(3));
}
