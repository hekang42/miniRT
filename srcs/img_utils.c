/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:34:26 by hekang            #+#    #+#             */
/*   Updated: 2021/03/17 20:25:21 by hekang           ###   ########.fr       */
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
	(result->img = (int **)ft_calloc(width + 1, sizeof(int *)));
	w = -1;
	while (++w < width)
	{
		(result->img[w] = (int *)ft_calloc(height + 1, sizeof(int)));
		h = -1;
		while (++h < height)
			result->img[w][h] = 0;
	}
	return (result);
}
