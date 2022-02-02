/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:42:17 by dforte            #+#    #+#             */
/*   Updated: 2022/02/01 20:42:58 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef unsigned int	t_uint;

int		ft_strchr(char *s, char c);
char	*get_line(char *save, int fd);
char	*get_next_line(int fd);
char	*ft_save(char *save, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, t_uint start, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif