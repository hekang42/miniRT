/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:47:31 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 13:58:47 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				ft_isdigit_comma(char *s)
{
	int			n;
	int			size;
	int			cnt;

	cnt = 0;
	size = ft_strlen(s);
	n = 0;
	while (s[n])
	{
		if (!((s[n] >= '0' && s[n] <= '9') || (s[n] == '.')
		|| (s[n] == ',') || (s[n] == '-')))
			return (FALSE);
		if (s[n] == ',' || s[n] == '-' || s[n] == '.')
			if (n == size - 1)
				return (FALSE);
		if (s[n] == ',')
			cnt++;
		if (size - 1 == n)
			break ;
		n++;
	}
	if (!(cnt == 0 || cnt == 2))
		return (FALSE);
	return (TRUE);
}

void			parse_check(char **s, int n, char *type)
{
	int			success;

	success = 1;
	if (s == 0 || s[n + 1])
	{
		printf("Error\n ** Init %s \n", type);
		exit(EXIT_SUCCESS);
	}
	while (n > 2)
	{
		if (s[n])
			if (!ft_isdigit_comma(s[n]))
			{
				printf("Error\n ** Init %s \n", type);
				exit(EXIT_SUCCESS);
			}
		n--;
	}
}
