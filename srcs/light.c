/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:33:43 by hekang            #+#    #+#             */
/*   Updated: 2021/02/15 15:21:03 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light     *init_light(t_vec *ori, double ratio, t_vec *color)
{
    t_light *result;

    result = (t_light *)malloc(sizeof(t_light));
    result->origin = ori;
    result->ratio = ratio;
    result->color = color;
    return (result);
}