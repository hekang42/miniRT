/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:23:49 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 19:35:29 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		cnt;

	cnt = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[cnt])
	{
		str[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}
