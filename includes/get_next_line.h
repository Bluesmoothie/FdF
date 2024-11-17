/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:23:13 by ygille            #+#    #+#             */
/*   Updated: 2024/11/17 19:54:37 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*add_char(char c, char *line);
char	*empty_line(void);

int		ft_strlen_g(const char *s);
int		ft_strlcpy_g(char *dst, const char *src, int size);
char	*protect(char *str);

#endif