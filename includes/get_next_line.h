/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:12:45 by hekang            #+#    #+#             */
/*   Updated: 2021/02/15 14:23:40 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"
# include "minirt.h"

// size_t	ft_strlen(const char *s);
// void	*ft_memcpy(void *dst, const void *src, size_t n);
// void	*ft_memset(void *b, int c, size_t len);
// char	*ft_strdup(const char *s1);
// void	*ft_calloc(size_t count, size_t size);
int		get_next_line(int fd, char **line);
// char	*ft_strjoin(char *s1, char *s2);
int		checknl(char *s);

#endif
