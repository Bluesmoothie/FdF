/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curves_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:49:33 by ygille            #+#    #+#             */
/*   Updated: 2024/12/19 13:00:14 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	apply_angle(int *x, int *y, int angle)
{
	if (angle == ANG_UP)
		return;
	else if (angle == ANG_DOWN)
		*y = WIDTH - *y;
	else if (angle == ANG_LEFT)
		*x = HEIGHT - *x;
	else if (angle == ANG_RIGHT)
	{
		*x = HEIGHT - *x;
		*y = WIDTH - *y;
	}
}
