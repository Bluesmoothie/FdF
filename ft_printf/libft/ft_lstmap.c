/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:46:31 by ygille            #+#    #+#             */
/*   Updated: 2024/11/14 13:02:15 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*next;
	t_list	*tmp;

	(void) del;
	map = NULL;
	if (lst != NULL)
	{
		map = ft_lstnew(f (lst->content));
		lst = lst->next;
		tmp = map;
	}
	while (lst != NULL)
	{
		next = ft_lstnew(f (lst->content));
		lst = lst->next;
		ft_lstadd_back(&tmp, next);
		tmp = next;
	}
	return (map);
}
