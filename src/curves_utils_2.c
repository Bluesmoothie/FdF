/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curves_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:49:33 by ygille            #+#    #+#             */
/*   Updated: 2025/02/07 20:20:42 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_angle(int *x, int *y, int angle)
{
	int	tx;
	int	ty;

	tx = *x;
	ty = *y;
	if (angle == ANG_UP)
	{
		*x = ty;
		*y = tx;
	}
	else if (angle == ANG_DOWN)
	{
		*x = HEIGHT - ty;
		*y = WIDTH - tx;
	}
	else if (angle == ANG_LEFT)
		*x = HEIGHT - tx;
	else if (angle == ANG_RIGHT)
		*y = WIDTH - ty;
}
