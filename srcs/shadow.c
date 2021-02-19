/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:17:46 by hekang            #+#    #+#             */
/*   Updated: 2021/02/17 22:32:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     in_shadow(t_scene *scene, t_hit_record *rec)
{
    t_ray           *light_ray;
    double          light_length;

    // light_ray = create_ray(rec->p, vec_sub(rec->p, scene->light->origin));
    light_ray = create_ray(rec->p, vec_sub(scene->light->origin, rec->p));
    // light_ray = create_ray(scene->light->origin, vec_sub(rec->p, scene->light->origin));
    // light_ray = create_ray(scene->light->origin, vec_sub(scene->light->origin, rec->p));
    light_ray->dir = vec_unit(light_ray->dir);
    // rec = hit_record_new();
    light_length = vec_len(vec_sub(scene->light->origin, rec->p));
    rec->t_max = light_length;
    rec->ray = light_ray;
    // printf("light_ray_ori : %f %f %f \n", light_ray->orig->x,light_ray->orig->y, light_ray->orig->z );
    // printf("rec->p : %f %f %f \n", rec->p->x,rec->p->y, rec->p->z );
    if (hitlst_hit(scene->obj, rec))
        return (TRUE);
    return (FALSE);
}