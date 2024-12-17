/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axonometric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:51:19 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 17:31:46 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Axonometric projection formulas
*/

int	axo_x(int x, int z)
{
	return ((x - z) / sqrt(2));
}

int	axo_y(int x, int y, int z)
{
	return (x + y + z / sqrt(3));
}
