/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:23:51 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 15:54:43 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnum(char *s, char c)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			num++;
		}
		else
			i++;
	}
	return (num);
}

void	str_malloc_copy(char *s, char c, size_t num, char **res)
{
	size_t	x;
	size_t	i;
	size_t	len;
	size_t	cnt;

	cnt = 0;
	i = 0;
	x = 0;
	while (s[i] && x < num)
	{
		len = 0;
		if (s[i] != c)
		{
			while (s[i + len] != c && s[i + len])
				len++;
			if (!(res[x] = ft_calloc(sizeof(char), len + 1)))
			{
				while (res[cnt])
					free(res[cnt++]);
				return ;
			}
			ft_strlcpy(res[x++], s + i, len + 1);
		}
		i += len + (len == 0 ? 1 : 0);
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	num;
	char	**res;

	if (s == 0)
		return (0);
	num = ft_strnum((char *)s, c);
	res = ft_calloc(sizeof(char *), num + 1);
	if (res == 0)
		return (0);
	str_malloc_copy((char *)s, c, num, res);
	res[num] = 0;
	return (res);
}
