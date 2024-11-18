/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:05:15 by ygille            #+#    #+#             */
/*   Updated: 2024/11/18 13:00:32 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	pixel_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void	test_rainbow(t_mlx *mlx)
{
	(void) mlx;
	return ;
}
