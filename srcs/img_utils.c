/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:34:26 by hekang            #+#    #+#             */
/*   Updated: 2021/01/15 15:20:08 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img_data      *create_img_data(int width, int height)
{
    t_img_data  *result;
    int         h;
    int         w;
    
    result = (t_img_data *)malloc(sizeof(t_img_data));
    result->height = height;
    result->width = width;
    result->img = (int **)malloc(sizeof(int *) * width);
    w = -1;
    while(++w < width)
    {
        result->img[w] = (int *)malloc(sizeof(int) * height);
        h = -1;
        while (++h < height)
            result->img[w][h] = 0;
    }
    return (result);
}