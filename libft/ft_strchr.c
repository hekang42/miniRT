/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:05:16 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 19:25:18 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	if (c == 0)
		return ((char *)s + ft_strlen(s));
	cnt = 0;
	while (s[cnt])
	{
		if (s[cnt] == c)
			return ((char *)(s + cnt));
		cnt++;
	}
	return (0);
}
