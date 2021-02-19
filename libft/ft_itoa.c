/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:42:52 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 20:18:43 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checkminus(int n, char *str)
{
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	long	value;
	int		len;
	char	*str;

	len = n < 1 ? 1 : 0;
	value = n < 0 ? -(long)n : (long)n;
	while (value != 0)
	{
		value = value / 10;
		len++;
	}
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	str[len] = '\0';
	value = n < 0 ? -(long)n : (long)n;
	while (len > 0)
	{
		str[len - 1] = value % 10 + '0';
		value = value / 10;
		len--;
	}
	checkminus(n, str);
	return (str);
}
