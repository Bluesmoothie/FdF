/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:48 by ygille            #+#    #+#             */
/*   Updated: 2024/11/26 17:25:46 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	iso_x(int x, int y)
{
	return (abs((int)(((x - y) * cos(ANGLE)) + OFFSET_X)));
}

int	iso_y(int x, int y, int z)
{
	return (abs((int)(((x + y) * sin(ANGLE) - z) + OFFSET_Y)));
}
