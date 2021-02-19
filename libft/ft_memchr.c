/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:23:53 by hekang            #+#    #+#             */
/*   Updated: 2020/10/05 17:49:26 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*us;

	us = (unsigned char *)s;
	cnt = 0;
	while (cnt < n)
	{
		if (us[cnt] == (unsigned char)c)
			return (us + cnt);
		cnt++;
	}
	return (0);
}
