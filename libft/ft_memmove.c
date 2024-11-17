/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:36:03 by ygille            #+#    #+#             */
/*   Updated: 2024/11/12 18:28:27 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destc;
	const char	*srcc;

	if (dest == NULL && src == NULL)
		return (dest);
	destc = (char *) dest;
	srcc = (const char *) src;
	if (destc < srcc)
		ft_memcpy (dest, src, n);
	else
	{
		while (n--)
			destc[n] = srcc[n];
	}
	return (dest);
}
