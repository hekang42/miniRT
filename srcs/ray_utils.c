/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:54:27 by hekang            #+#    #+#             */
/*   Updated: 2021/01/25 15:22:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray       *create_ray(t_vec *origin, t_vec *direction)
{
    t_ray       *result;

    result = (t_ray *)malloc(sizeof(t_ray));
    result->orig = origin;
    result->dir = direction;
    return (result);
}

t_vec       *ray_at(t_ray *ray, double t)
{
	t_vec	*result;
	t_vec	*tmp_vec;

	tmp_vec = vec_mul_const(ray->dir, t);
	result = vec_add(tmp_vec, ray->orig);
	free(tmp_vec);
    return (result);
}

void       free_ray(t_ray *ray, int is_ray_free)
{
    if (ray == NULL)
        return ;
    if (ray->orig != NULL && is_ray_free)
        free(ray->orig);
    free(ray->dir);
    free(ray);
}