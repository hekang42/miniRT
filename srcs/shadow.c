/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:17:46 by hekang            #+#    #+#             */
/*   Updated: 2021/03/08 13:42:16 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     in_shadow(t_scene *scene, t_light *light, t_hit_record *rec)
{
    t_ray           *light_ray;
    double          light_length;
    t_vec           *p;
    t_hit_record    *rec_l;

    rec_l = hit_record_new();
    p = vec_add(rec->p, vec_mul_const(rec->normal, 0.000001));
    // p = rec->p;
    light_ray = create_ray(p, vec_unit(vec_sub(light->origin, p)));
    light_length = vec_len(vec_sub(light->origin, p));
    rec_l->p = p;
    rec_l->t_max = light_length;
    rec_l->ray = light_ray;
    if (hitlst_hit(scene->obj, rec_l))
        return (TRUE);
    return (FALSE);
}