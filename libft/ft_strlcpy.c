/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:52:27 by hekang            #+#    #+#             */
/*   Updated: 2020/10/05 23:22:59 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *src,
		size_t dstsize)
{
	size_t cnt;

	cnt = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (cnt < ft_strlen(src) && cnt + 1 < dstsize)
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	if (dstsize > 0)
		dst[cnt] = 0;
	return (ft_strlen(src));
}
