/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:11:50 by hekang            #+#    #+#             */
/*   Updated: 2021/02/15 14:24:06 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checknl(char *s)
{
	int	cnt;

	cnt = 0;
	if (s == 0)
		return (-1);
	while (s[cnt])
	{
		if (s[cnt] == '\n')
			return (cnt);
		cnt++;
	}
	return (-1);
}

int		befree(char **str)
{
	if (*str)
		free(*str);
	return (-1);
}

int		return_all(char **backup, char **line, int rd_size, int idx)
{
	char	*temp;

	if (rd_size < 0)
		return (-1);
	if (!*backup)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if (idx != -1)
		(*backup)[idx] = 0;
	if (!(*line = ft_strdup(*backup)))
		return (befree(backup));
	if (rd_size == 0 && idx == -1)
	{
		free(*backup);
		*backup = 0;
		return (0);
	}
	if (!(temp = ft_strdup(*backup + idx + 1)))
		return (befree(backup));
	free(*backup);
	*backup = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	int			idx;
	char		*temp;

	rd_size = 1;
	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	while (((idx = checknl(backup[fd])) == -1) &&
		((rd_size = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		temp = ((backup[fd] == NULL) ? ft_strdup(buff) :
			ft_strjoin(backup[fd], buff));
		if (!temp)
			return (befree(&backup[fd]));
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		free(backup[fd]);
		backup[fd] = temp;
		if ((idx = checknl(backup[fd])) != -1)
			break ;
	}
	return (return_all(&backup[fd], line, rd_size, idx));
}
