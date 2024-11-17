/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:37:39 by ygille            #+#    #+#             */
/*   Updated: 2024/11/12 16:35:00 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destc;
	const char	*srcc;
	size_t		count;

	if (dest == NULL && src == NULL)
		return (dest);
	destc = (char *) dest;
	srcc = (const char *) src;
	count = 0;
	while (count < n)
	{
		destc[count] = srcc[count];
		count++;
	}
	return (dest);
}
