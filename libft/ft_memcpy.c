/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:19:16 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 01:36:47 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	cnt;

	if (dst == 0 && src == 0)
		return (dst);
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = ((unsigned char *)src)[cnt];
		cnt++;
	}
	return (dst);
}
