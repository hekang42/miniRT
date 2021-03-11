/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:13:35 by hekang            #+#    #+#             */
/*   Updated: 2021/03/11 10:35:04 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int		check_ddigit(const char *str)
{
	int	cnt;
	int	i;
	int	minus;

	cnt = 0;
	i = 0;
	minus = 1;
	while (str[cnt] == ' ' || str[cnt] == '\t' || str[cnt] == '\n' ||
			str[cnt] == '\v' || str[cnt] == '\f' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '+' || str[cnt] == '-')
	{
		if (str[cnt] == '-')
			minus = -1;
		cnt++;
	}
	while (str[cnt + i])
		if (str[cnt + i] >= '0' && str[cnt + i] <= '9' && str[cnt + i] == '.')
			i++;
		else
			break ;
	return (i * minus);
}

double	ft_atod(const char *str)
{
	int		cnt;
	double	result;
	int		minus;
	int		n;

	if (check_ddigit(str) >= 20 || check_ddigit(str) <= -20)
		return (check_ddigit(str) > 0 ? -1 : 0);
	cnt = 0;
	minus = 1;
	result = 0;
	while (str[cnt] == ' ' || str[cnt] == '\t' || str[cnt] == '\n' ||
			str[cnt] == '\v' || str[cnt] == '\f' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '+' || str[cnt] == '-')
		if (str[cnt++] == '-')
			minus = -1;
	while (str[cnt] >= '0' && str[cnt] <= '9')
		result = result * 10 + str[cnt++] - '0';
	n = 1;
	if (str[cnt++] >= '.')
		while (str[cnt] >= '0' && str[cnt] <= '9')
			result = result + (str[cnt++] - '0') * pow(0.1, n++);
	return (result * minus);
}
