/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:18:23 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 19:33:31 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cnt;
	char	*result;

	if (s == 0)
		return (NULL);
	cnt = 0;
	if (!(result = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while ((cnt < len) && (cnt + start < ft_strlen(s)))
	{
		result[cnt] = s[cnt + start];
		cnt++;
	}
	result[cnt] = '\0';
	return (result);
}
