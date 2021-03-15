/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:34:26 by hekang            #+#    #+#             */
/*   Updated: 2021/03/15 16:45:30 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img_data		*create_img_data(int width, int height)
{
	t_img_data	*result;
	int			h;
	int			w;

	result = (t_img_data *)ft_calloc(1, sizeof(t_img_data));
	result->height = height;
	result->width = width;
	if (!(result->img = (int **)ft_calloc(width, sizeof(int *))))
		printf("malloc error\n\n\n\n");
	w = -1;
	while (++w < width)
	{
		if (!(result->img[w] = (int *)ft_calloc(height, sizeof(int))))
			printf("malloc error\n\n\n\n");
		h = -1;
		while (++h < height)
			result->img[w][h] = 0;
	}
	return (result);
}
