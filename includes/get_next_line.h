/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:12:45 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 16:13:23 by hekang           ###   ########.fr       */
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

int		get_next_line(int fd, char **line);
int		checknl(char *s);

#endif
