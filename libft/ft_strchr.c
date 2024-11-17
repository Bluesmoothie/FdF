/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:28:57 by ygille            #+#    #+#             */
/*   Updated: 2024/11/12 19:44:16 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	while (c > 127)
		c -= 128;
	while (s[count] != '\0' && s[count] != c)
		count++;
	if (s[count] == c)
		return ((char *)&s[count]);
	else
		return (NULL);
}
