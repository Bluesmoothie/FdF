/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:48 by ygille            #+#    #+#             */
/*   Updated: 2025/02/07 20:21:04 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Isometric projection formulas
*/

int	iso_x(int x, int z)
{
	return ((x - z) / sqrt(2));
}

int	iso_y(int x, int y, int z)
{
	return (((x + z) + (2 * y)) / sqrt(6));
}
