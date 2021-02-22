/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:29:47 by hekang            #+#    #+#             */
/*   Updated: 2021/02/22 15:21:01 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int             vec_each_check(t_vec *a, double r, t_vec *n)
{
    t_vec   t;
    t_vec *t_r;
    t_vec *tmp;
    // radian = t * 3.141592 / 180;
    t.x = (n->x) * PI;
    t.y = (n->y) * PI;
    t.z = (n->z) * PI;
    t_r = vec_create(0,0,0);
    tmp = vec_create(0,0,0);
    //x orient
    t_r->x = a->x;
    t_r->y = a->y * cos(t.x) - a->z * sin(t.x);
    t_r->z = a->y * sin(t.x) + a->z * cos(t.x);
    //z orient
    tmp->x = t_r->x * cos(t.z) - t_r->y * sin(t.z);
    tmp->y = t_r->x * sin(t.z) + t_r->y * cos(t.z);
    tmp->z = t_r->z;
    //y orient
    t_r->x = tmp->x * cos(t.y) + tmp->z * sin(t.y);
    t_r->y = tmp->y;
    t_r->z = -1 * tmp->x * sin(t.y) + tmp->z * cos(t.y);
    // if ((fabs(t_r->x) <= r && fabs(t_r->y) <= r && fabs(t_r->z) <= r)
    // && (pow(pow(fabs(t_r->x), 2) + pow(fabs(t_r->y), 2) + pow(fabs(t_r->z), 2), 0.5) == r))
    if (pow(pow(fabs(t_r->x), 2) + pow(fabs(t_r->y), 2) + pow(fabs(t_r->z), 2), 0.5) == r)
        return (TRUE);
    return (FALSE);
}

int             cylinder_hit(void *obj, t_ray *r, t_hit_record *rec)
{
    double      denominator;
    t_cylinder  *cy;
    t_vec       *oc;
    double      t;
    t_vec       *hc;
    double      h;

    cy = ((t_cylinder *)obj);
    denominator = vec_dot(cy->normal, r->dir);
    if (fabs(denominator) < 0.000001)
        return (FALSE);
    oc = vec_sub(cy->origin, r->orig);
    t = vec_dot(oc, cy->normal) / denominator;
    h = 0;
    if (t < rec->t_min || t > rec->t_max)
    {
        while (h < cy->height)
        {
            oc = vec_sub(vec_add(cy->origin, vec_mul_const(cy->normal, h)), r->orig);
            t = vec_dot(oc, cy->normal) / denominator;
            if (t > rec->t_min && t < rec->t_max)
                break ;
            h = h + 0.5;
        }
        if (t < rec->t_min || t > rec->t_max)
            return (FALSE);
    }
    rec->p = ray_at(r, t);


    hc = vec_add(cy->origin, vec_mul_const(cy->normal,  
    vec_dot(vec_sub(rec->p, cy->origin), cy->normal)));

    // hc = vec_add(cy->origin, vec_mul_const(cy->normal,  
    // vec_dot(vec_sub(rec->p, cy->origin), cy->normal)));

    // tc = cy->origin + n * height;

    if (vec_each_check(vec_sub(rec->p, hc), cy->diameter / 2, cy->normal))
    {
        rec->t = t;
        rec->normal = vec_unit(vec_sub(rec->p, hc));
        rec->color = cy->color;
        return (TRUE);
    }
    return (FALSE);
}