/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:25:09 by ygille            #+#    #+#             */
/*   Updated: 2024/12/17 13:27:55 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	calc_map_size(int fd)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = get_next_line(fd);
	while (ptr != NULL)
	{
		free(ptr);
		ptr = get_next_line(fd);
		i++;
	}
	return (i);
}
