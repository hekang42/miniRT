/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:37:53 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 19:34:50 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		to_find(char c, char const *set)
{
	int	cnt;

	cnt = 0;
	while (set[cnt])
	{
		if (set[cnt] == c)
			return (1);
		cnt++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		len;

	if (s1 == 0)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (start < end)
	{
		if (to_find(s1[start], set) == 0)
			break ;
		start++;
	}
	while (end > 0 && to_find(s1[end], set) != 0)
		end--;
	len = end > start ? end - start + 1 : 0;
	if (len <= 1)
		return (ft_strdup(""));
	if (!(str = ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	ft_strlcpy(str, s1 + start, len + 1);
	return (str);
}
