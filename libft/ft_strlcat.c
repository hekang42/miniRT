/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:32:08 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 19:58:00 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (i < dstsize)
	{
		while (src[j] && i + j + 1 < dstsize)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
	}
	while (src[j])
		j++;
	if (i > dstsize)
		return (dstsize + j);
	else
		return (i + j);
}
