/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:13:31 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 19:24:18 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;
	size_t			cnt;

	if (dst == src)
		return (dst);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (dst > src)
	{
		while (len-- > 0)
			udst[len] = usrc[len];
	}
	else
	{
		cnt = 0;
		while (cnt < len)
		{
			udst[cnt] = usrc[cnt];
			cnt++;
		}
	}
	return (dst);
}
