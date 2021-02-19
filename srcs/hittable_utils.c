/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:14:55 by hekang            #+#    #+#             */
/*   Updated: 2021/02/19 15:24:36 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hittable          *hittable_create(void *obj, int obj_type)
{
    t_hittable      *result;

    result = (t_hittable *)malloc(sizeof(t_hittable));
    result->obj = obj;
    result->obj_type = obj_type;
    if (obj_type == OBJ_SPHERE)
        result->hit = &sphere_hit;
    else if (obj_type == OBJ_PLANE)
        result->hit = &plane_hit;
    else if (obj_type == OBJ_SQUARE)
        result->hit = &square_hit;
    else if (obj_type == OBJ_CYLINDER)
        result->hit = &cylinder_hit;
    else if (obj_type == OBJ_CYLINDER_2)
        result->hit = &cylinder_hit_2;
    else if (obj_type == OBJ_TRIANGLE)
        result->hit = &triangle_hit;
    return (result);
}